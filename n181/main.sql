# 181. Employees Earning More Than Their Managers

# Write your MySQL query statement below

SELECT Inferior.Name AS Employee
FROM Employee Inferior, Employee Manager 
WHERE Inferior.ManagerId = Manager.Id 
AND Inferior.Salary > Manager.Salary;