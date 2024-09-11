# Write your MySQL query statement below
with cte as (
    select assignment1+assignment2+assignment3 as tot from Scores
    order by tot desc
)

select max(tot)-min(tot) as difference_in_score  from cte;