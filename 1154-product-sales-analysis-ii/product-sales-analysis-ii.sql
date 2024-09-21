
# Write your MySQL query statement below
with cte as(
select distinct(p.product_id), sum(quantity)over(partition by p.product_id )
as total_quantity
from Product p left join Sales s on p.product_id = s.product_id
)
select * from cte where total_quantity is not null