# Write your MySQL query statement below
select w.id from weather w
join weather c on datediff(w.recordDate,c.recordDate)=1
where w.temperature>c.temperature;