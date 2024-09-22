# Write your MySQL query statement 
with cte as (
select r.interview_id,round_id,score,candidate_id,years_of_exp
from Rounds r left join Candidates c on r.interview_id = c.interview_id
)

,cte2 as(
select candidate_id,sum(score) as tot,years_of_exp  from cte
group by candidate_id)

select candidate_id
from cte2
where tot >15 and years_of_exp >=2


