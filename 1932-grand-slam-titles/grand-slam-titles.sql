# Write your MySQL query statement below
with wcte as(
select  Wimbledon as player_id ,count(Wimbledon) as titles
from Championships
group by Wimbledon
),

 fcte as(
select  Fr_open as player_id ,count(Fr_open) as titles
from Championships
group by Fr_open

),

ucte as(
select  US_open as player_id ,count(US_open) as titles
from Championships
group by US_open

),

 acte as (
    select  Au_open as player_id ,count(Au_open) as titles
from Championships
group by Au_open
)

select p.player_id, p.player_name ,(coalesce(w.titles,0)+coalesce(f.titles,0)+coalesce(u.titles,0)+coalesce(a.titles,0)) as grand_slams_count from Players p
left join wcte w 
on p.player_id =w.player_id
left join fcte f
on p.player_id =f.player_id
left join ucte u
on p.player_id =u.player_id
left join acte a
on p.player_id =a.player_id
where (coalesce(w.titles,0)+coalesce(f.titles,0)+coalesce(u.titles,0)+coalesce(a.titles,0)) >0;
