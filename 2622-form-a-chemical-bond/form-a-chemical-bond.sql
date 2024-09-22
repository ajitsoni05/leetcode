# Write your MySQL query statement below
with cte as(
select e.symbol as metal, e1.symbol as nonmetal,e.type as t1, e1.type as t2
from Elements e cross join Elements e1
)

select metal,nonmetal from cte
where t1= 'Metal' and t2 = 'Nonmetal'
