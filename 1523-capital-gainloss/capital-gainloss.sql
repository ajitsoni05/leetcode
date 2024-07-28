# Write your MySQL query statement below

select stock_name , SUM(Case when operation = 'Buy' then price*(-1) else price END) as capital_gain_loss
from Stocks
group by stock_name;