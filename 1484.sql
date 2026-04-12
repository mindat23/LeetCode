--key problem is group_concat
select sell_date,count(DISTINCT product) as num_sold,
group_concat(DISTINCT product order by product ASC) as products
from Activities
group by sell_date
order by sell_date ASC,num_sold DESC;