# Write your MySQL query statement below
select tweet_id from Tweets where content like "%@%@%@%@%" or content like "%#%#%#%#%" or length(content)>140;