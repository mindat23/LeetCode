--Use CTE
WITH ranked_employee AS (
    SELECT *,
        DENSE_RANK() OVER (
            PARTITION BY e.departmentId 
            ORDER BY e.salary DESC
        ) AS ranking
    FROM Employee e
)

SELECT 
    d.name AS Department,
    r.name AS Employee,
    r.salary AS Salary
FROM ranked_employee r
JOIN Department d 
    ON d.id = r.departmentId
WHERE r.ranking <= 3;