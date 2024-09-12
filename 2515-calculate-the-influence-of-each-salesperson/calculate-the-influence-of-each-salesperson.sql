# Write your MySQL query statement below
with cte as(
select c.salesperson_id, sum(s.price) as total
from Sales s
left join Customer c on c.customer_id = s.customer_id
group by salesperson_id
)

select s.salesperson_id,s.name, coalesce(c.total,0) as total
from Salesperson s left join cte c
on s.salesperson_id = c.salesperson_id