# Write your MySQL query statement below
(
    select u.name as results from Users u 
    join MovieRating m 
    on u.user_id=m.user_id group by u.user_id,u.name
    order by count(*) desc,u.name asc limit 1
)
union all
( 
    select mo.title from Movies mo 
    join MovieRating m on 
    mo.movie_id=m.movie_id where m.created_at between '2020-02-01' and '2020-02-29'
    group by mo.movie_id,mo.title 
    order by avg(m.rating) desc, mo.title asc limit 1
);