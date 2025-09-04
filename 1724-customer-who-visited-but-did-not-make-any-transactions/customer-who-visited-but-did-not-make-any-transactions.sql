# Write your MySQL query statement below
SELECT DISTINCT customer_id, COUNT(customer_id) as count_no_trans
FROM Visits as v
LEFT JOIN Transactions as t
ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL
GROUP BY customer_id