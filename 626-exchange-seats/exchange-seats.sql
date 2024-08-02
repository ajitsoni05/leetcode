# Write your MySQL query statement below
## Here we will learn about common table expression cte
with cte as(
select *, LEAD(id) over(order by id ) as next , LAG(id) over(order by id ) as prev
from Seat
)

select case when id%2=1 and next is not null then next 
when id%2=0 then prev
else id end as id,student
from cte
order by id;