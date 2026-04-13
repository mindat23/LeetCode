--Use window function để lấy min_year của từng product_id
with cte as(
    select *,
    min(year) over(partition by product_id) as min_year
    from Sales 
)

select product_id,year as first_year,quantity,price
from cte
where year = min_year;