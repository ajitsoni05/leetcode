# Write your MySQL query statement below
with cte as(
select e1.employee_id,e1.manager_id, e1.salary as esal, e2.salary as msal
from Employees e1
left join Employees e2 
on e2.employee_id = e1.manager_id
where e1.manager_id is not null)

select employee_id from cte where msal is null and esal <30000
order by employee_id



-- select manager_id as employee_id,
-- from Employees
-- where manager_id is not null;