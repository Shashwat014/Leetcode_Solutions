# Write your MySQL query statement below
with ans as(select id ,temperature,recordDate , lag(recordDate) over (order by recordDate) as prev_day
,lag(temperature) over (order by recordDate) as previous from Weather)
select id as Id from ans where temperature > previous and datediff(recordDate,prev_day)=1;