# Write your MySQL query statement below
select u.name , sum(t.amount) as balance
From Transactions t
inner join Users u
on t.account = u.account 
group by u.name 
having sum(t.amount)>10000
