# Write your MySQL query statement below
select machine_id , round(abs(sum(case when activity_type ='start' then timestamp else -1*timestamp end))/count(distinct(process_id)),3) as processing_time
from Activity 
group by machine_id;