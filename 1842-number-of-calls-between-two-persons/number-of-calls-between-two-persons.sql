# Write your MySQL query statement below

with cte as(
select 
(case when from_id < to_id then from_id else to_id end) as 'from_id',(case when from_id >= to_id then from_id else to_id end) as 'to_id' , duration
from calls
)
select from_id as person1,to_id as person2, count(*) as call_count,sum(duration) as total_duration from cte
group by from_id,to_id