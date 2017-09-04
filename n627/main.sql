# 627. Swap Salary

UPDATE salary SET sex = (CASE sex WHEN 'm' THEN 'f' WHEN 'f' THEN 'm' ELSE sex END)