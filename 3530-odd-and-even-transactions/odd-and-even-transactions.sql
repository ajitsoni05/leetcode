# Write your MySQL query statement below
select transaction_date , SUM(CASE when amount%2 = 1 then amount else 0 end) as odd_sum, SUM(Case when amount%2 =0 then amount else 0 end) as even_sum
from transactions
group by transaction_date
order by transaction_date