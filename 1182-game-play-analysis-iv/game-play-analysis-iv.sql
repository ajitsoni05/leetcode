# Write your MySQL query statement below

with cte1 as (
select player_id, min(event_date) as first_login
from Activity 
group by player_id )

, cte2 as (
select player_id, first_login , DATE_ADD(first_login, Interval 1 day) as next_login
from cte1 
)

-- select * from cte2;
select ROUND(
(select count(distinct(player_id)) from Activity where (player_id,event_date) in( select player_id , next_login as event_date from cte2 )) /( select count(distinct(player_id)) from Activity),2 )
 as fraction
