--Use union all
--Lấy từng bảng
--Sau đó nối vô


(
select u.name as results
from Users u
join MovieRating m
on u.user_id = m.user_id
group by m.user_id 
order by count(m.rating) DESC,u.name ASC limit 1
)

union all
(
select m1.title
from Movies m1
join MovieRating m2
on m1.movie_id = m2.movie_id
where month(m2.created_at) = 2 and year(m2.created_at) = 2020
group by m2.movie_id 
order by avg(m2.rating) DESC,m1.title ASC
limit 1
) 