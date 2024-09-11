# Write your MySQL query statement below
with cte as (
    select product_id, Width*Length*Height as vol from Products
)

-- select * from cte;

 select w.name as warehouse_name ,sum(c.vol*w.units) as volume
 From Warehouse w join cte c on w.product_id = c.product_id group by warehouse_name;