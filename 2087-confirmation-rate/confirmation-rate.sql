# Write your MySQL query statement below
select u.user_id, coalesce(round(sum(case when c.action='confirmed' then 1 else  0 end)/count(action),2),0) as confirmation_rate from Signups u
left join Confirmations c on u.user_id = c.user_id
group by user_id