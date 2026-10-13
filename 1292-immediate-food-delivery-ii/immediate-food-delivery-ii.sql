# Write your MySQL query statement below
with cte as (select *  , row_number() over (partition by customer_id  order by order_date) as rn from Delivery ) 

select   round( sum(case when order_date=customer_pref_delivery_date and rn=1 then 1 else 0 end)/sum(case when rn=1 then 1  else 0 end)*100 , 2) as immediate_percentage  from cte ; 