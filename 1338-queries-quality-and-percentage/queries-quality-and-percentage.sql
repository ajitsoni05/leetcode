# Write your MySQL query statement below
select query_name , round(avg((rating/position)),2) as quality, round(100-sum(floor((rating/3)))/count(rating)*100,2) as poor_query_percentage  from Queries group by query_name having query_name != 'null';