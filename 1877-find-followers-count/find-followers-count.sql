# Write your MySQL query statement below
select distinct user_id , count(follower_id) over (partition by user_id) as followers_count from Followers; 