# Write your MySQL query statement below
with cte as(
select candidate_id , group_concat(skill) as skills
from Candidates
group by candidate_id)

select candidate_id from cte 
where skills like "%Python%" and skills like "%Tableau%" and skills like "%PostgreSQL%"


-- select * from cte