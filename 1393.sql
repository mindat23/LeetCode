-- Pivot (xoay)
with cte as(
    select stock_name,
    sum(case when operation = 'Buy' then price end) as buy_row,
    sum(case when operation = 'Sell' then price end) as sell_row
    from Stocks
    group by stock_name
)

select stock_name,
sell_row - buy_row as capital_gain_loss
from cte;