# Write your MySQL query statement below
select p.product_name , sum(o.unit) as unit from Products p 
join Orders o on o.product_id = p.product_id where o.order_date >'2020-01-31' and o.order_date <= '2020-02-29'  group by p.product_id having unit >=100  ;