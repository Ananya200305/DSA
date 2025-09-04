# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) as attended_exams
FROM Students as s
CROSS JOIN Subjects as sub
LEFT JOIN Examinations as e
ON e.student_id = s.student_id AND sub.subject_name = e.subject_name
GROUP BY s.student_id, sub.subject_name, s.student_name
ORDER BY s.student_id, sub.subject_name
