

with cte as (
    select product_id,sum(unit) as unit
    from Orders
    where month(order_date) = 2 and year(order_date) = 2020
    group by product_id
    having unit >= 100
)

select p.product_name,c.unit
from Products p
join cte c
on c.product_id = p.product_id;