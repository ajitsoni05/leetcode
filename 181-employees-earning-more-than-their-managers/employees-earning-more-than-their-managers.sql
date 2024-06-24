# Write your MySQL query statement below
select e.name as 'Employee' from Employee e
join Employee em on em.id=e.managerId where e.salary > em.salary 