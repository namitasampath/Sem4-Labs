

-- 1. Find the number of students in each course.
SELECT Course_ID, COUNT(*) AS NumberOfStudents 
FROM Takes 
GROUP BY Course_ID;


--2. Find those departments where the average number of students are greater than 10.
SELECT Dept_Name, AVG(Tot_Cred) AS AverageNumberOfStudents 
FROM Student 
GROUP BY Dept_Name 
HAVING AVG(Tot_Cred) > 10;

--3. Find the total number of courses in each department.
SELECT Dept_Name, COUNT(*) AS TotalCourses 
FROM Course 
GROUP BY Dept_Name;


--4. Find the names and average salaries of all departments whose average salary is greater than 42000
SELECT Dept_Name, AVG(Salary) AS AverageSalary 
FROM Instructor 
GROUP BY Dept_Name 
HAVING AVG(Salary) > 42000;


--5. Find the enrolment of each section that was offered in Spring 2009.
SELECT Course_ID, Section_ID, COUNT(*) AS Enrollment 
FROM Takes 
WHERE Semester = 'Spring' AND Year = 2009 
GROUP BY Course_ID, Section_ID;

--6. List all the courses with prerequisite courses, then display course id in increasing order
select Course_ID, Prereq_ID from Prereq ORDER BY Course_ID;

--7. Display the details of instructors sorting the salary in decreasing order.
select * from Instructor order by Salary desc;

--8. Find the maximum total salary across the departments.



--9. Find the average instructors’ salaries of those departments where the average salary is greater than 42000.
SELECT Dept_Name, AVG(Salary) AS AverageSalary 
FROM Instructor 
GROUP BY Dept_Name 
HAVING AVG(Salary) > 42000;

--10. Find the sections that had the maximum enrolment in Spring 2010


--11. Find the names of all instructors who teach all students that belong to ‘CSE’ department
select Dept_Name, Name AS Name
from Instructor 
GROUP BY Dept_Name
HAVING Dept_Name = 'Computer Science';


--12. Find the average salary of those department where the average salary is greater than 50000 and total number of instructors in the department are more than 5.
SELECT Dept_Name, AVG(Salary) AS AverageSalary 
FROM Instructor 
GROUP BY Dept_Name 
HAVING AVG(Salary) > 50000 AND count()>5;

--13.	Find all departments with the maximum budget.
SELECT dept_name, budget
FROM department
WHERE budget = (SELECT MAX(budget) FROM department);



