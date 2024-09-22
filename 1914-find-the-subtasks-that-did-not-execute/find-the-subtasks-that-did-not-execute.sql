# Write your MySQL query statement below

with recursive cte as(
    select * from Tasks
    union
    select task_id , (subtasks_count) -1 
    from cte
    where subtasks_count >1
)

-- select * from cte
select task_id, subtasks_count as subtask_id from cte  where (task_id,subtasks_count) not in (select task_id,subtask_id from Executed)