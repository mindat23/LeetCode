
--Use CTE and Windowfunction:
--Use CTE kết hợp windowfunction để đếm số lượng xuất hiện tiv_2015 và số lần trùng của lat và lon
--Query chính : xài where (điều kiện count(tiv_2015) > 1) và count(*) theo lat,lon = 1
with cte as(
    select *,
    count(*) over(partition by tiv_2015) AS cnt_tiv,
    count(*) over(partition by lat,lon) as cnt_loc
    from Insurance
)

select round(sum(tiv_2016),2) as tiv_2016
from cte
where cnt_tiv > 1 and cnt_loc = 1;