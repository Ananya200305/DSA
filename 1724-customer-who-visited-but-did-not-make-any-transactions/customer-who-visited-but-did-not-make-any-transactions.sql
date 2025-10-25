# Write your MySQL query statement below
SELECT customer_id , COUNT(customer_id) as count_no_trans
FROM Visits as v
LEFT JOIN Transactions as t
ON v.visit_id = t.visit_id
WHERE t.transaction_id is null
GROUP BY customer_id
