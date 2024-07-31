# Write your MySQL query statement below

select id, MAX(CASE when month ='Jan' then revenue else null end) as Jan_Revenue,
MAX(CASE when month ='Feb' then revenue else null end) as Feb_Revenue,
MAX(CASE when month ='Mar' then revenue else null end) as Mar_Revenue,
MAX(CASE when month ='Apr' then revenue else null end) as Apr_Revenue,
MAX(CASE when month ='May' then revenue else null end) as May_Revenue,
MAX(CASE when month ='Jun' then revenue else null end) as Jun_Revenue,
MAX(CASE when month ='Jul' then revenue else null end) as Jul_Revenue,
MAX(CASE when month ='Aug' then revenue else null end) as Aug_Revenue,
MAX(CASE when month ='Sep' then revenue else null end) as Sep_Revenue,
MAX(CASE when month ='Oct' then revenue else null end) as Oct_Revenue,
MAX(CASE when month ='Nov' then revenue else null end) as Nov_Revenue,
MAX(CASE when month ='Dec' then revenue else null end) as Dec_Revenue
from Department
group by id;