--Solution 1:
--Use dense_rank() instead rank()
/*Explain:
Dense_rank() is consectutive and not skip over rank is duplicate
*Example :
4.0 - 1
4.0 - 1
3.5 - 2
Rank() is not consecutive and skip over rank is duplicate
*Example:
4.0 - 1
4.0 - 1
3.5 - 3
That is the difference
*/
select score, DENSE_RANK() over(order by score DESC) as 'rank'
from Scores


--Solution 2: correlated subquery
/*
Subquery: count(s2.score)
if s2.score >= s1.score 
*/
select s1.score,
    (select count(distinct score)
        from Scores s2
        where s2.score >= s1.score
    ) as 'rank'
from Scores s1
order by s1.score DESC;