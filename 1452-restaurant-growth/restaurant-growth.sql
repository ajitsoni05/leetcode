# First group by dates
with cte1 as(
select visited_on, sum(amount) as amount
from Customer 
group by visited_on),

cte2 as(
select visited_on, sum(amount) over(order by visited_on rows between 6 preceding and current row) as amount , round(avg(amount) over(order by visited_on rows between 6 preceding and current row),2) as average_amount
from cte1 )

select * from cte2
where visited_on>=(select visited_on from cte2 limit 1)+6
order by visited_on