# Write your MySQL query statement below


with cte as(
select employee_id,name from Employees
),
cte2 as(
select (case when reports_to is not null then reports_to else 0 end) as employee_id ,   (select name from cte where employee_id = reports_to ) as name, count(*) as reports_count , round(sum(age)/count(*)) as average_age
from Employees 
group by reports_to
order by employee_id
)

select * from cte2 where employee_id != 0;

