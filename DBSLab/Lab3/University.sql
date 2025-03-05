--Implement the following Queries on UNIVERSITY Database:

/*
Set Operations
UNION (Use union all to retain duplicates):
1.	Find courses that ran in Fall 2022 or in Spring 2023
*/
SELECT course_id FROM Section WHERE semester = 'Fall' AND year = 2022 UNION ALL SELECT course_id FROM Section WHERE semester = 'Spring' AND year = 2023;

/*
INTERSECT (Use intersect all to retain duplicates):
2.	Find courses that ran in Fall 2022 and in spring 2023
*/
SELECT course_id FROM Section WHERE semester = 'Fall' AND year = 2022 INTERSECT SELECT course_id FROM Section WHERE semester = 'Spring' AND year = 2023;
/*
MINUS:
3.	Find courses that ran in Fall 2022 but not in Spring 2023
*/
SELECT course_id FROM Section WHERE semester = 'Fall' AND year = 2022 MINUS SELECT course_id FROM Section WHERE semester = 'Spring' AND year = 2023;
/*
Null values
4.	Find the name of the course for which none of the students registered.
*/
SELECT Title FROM Course WHERE course_id NOT IN (SELECT course_id   FROM Takes);

/*
Nested Subqueries
Set Membership (in / not in):
5.	Find courses offered in Fall 2022 and in Spring 2023.
*/
SELECT course_id FROM Section WHERE (semester = 'Fall' AND year = 2022) OR (semester = 'Spring' AND year = 2023);
/*
6.	Find the total number of students who have taken course taught by the instructor with ID 10101
*/
SELECT COUNT(DISTINCT ID)FROM Takes WHERE course_id IN (    SELECT course_id    FROM Teaches    WHERE ID = 10101);
/*
7.	Find courses offered in Fall 2022 but not in Spring 2023.
*/
SELECT course_id FROM Section WHERE semester = 'Fall' AND year = 2022 AND course_id NOT IN (    SELECT course_id    FROM Section    WHERE semester = 'Spring' AND year = 2023);

--8.	Find the names of all students whose name is same as the instructor’s name.
SELECT DISTINCT s.Name FROM Student s JOIN Instructor i ON s.Name = i.Name;

/*
Set Comparison (>=some/all)
9.	Find names of instructors with salary greater than that of some (at least one) instructor in the Biology department.
*/
SELECT Name FROM Instructor WHERE Salary > ANY (    SELECT Salary    FROM Instructor    WHERE Dept_name = 'Biology');
/*
10.	Find the names of all instructors whose salary is greater than the salary of all instructors in the Biology department.
*/
SELECT Name FROM Instructor WHERE Salary > ALL (    SELECT Salary    FROM Instructor    WHERE Dept_name = 'Biology');
/*
11.	Find the departments that have the highest average salary.
*/
SELECT Dept_name FROM Instructor GROUP BY Dept_name
HAVING AVG(Salary) = (
    SELECT MAX(dept_avg.avg_salary)
    FROM (
        SELECT AVG(Salary) AS avg_salary
        FROM Instructor
        GROUP BY Dept_name
    ) dept_avg
);
/*
12.	Find the names of those departments whose budget is lesser than the average salary of all instructors.
*/
SELECT Dept_name
FROM Department1001
WHERE Budget < (
    SELECT AVG(Salary)
    FROM Instructor
);
/*
Test for Empty Relations (exists/ not exists)
13.	Find all courses taught in both the Fall 2022 semester and in the Spring 2023 semester.
*/
SELECT course_id
FROM Section s1
WHERE semester = 'Fall' AND year = 2022
AND EXISTS (
    SELECT *
    FROM Section s2
    WHERE s2.course_id = s1.course_id
    AND s2.semester = 'Spring'
    AND s2.year = 2023
);
/*
14.	Find all students who have taken all courses offered in the Biology department.*/
SELECT ID
FROM Student s
WHERE NOT EXISTS (
    SELECT course_id
    FROM Course
    WHERE Dept_name = 'Biology'
    AND NOT EXISTS (
        SELECT *
        FROM Takes t
        WHERE t.ID = s.ID
        AND t.course_id = course.course_id
    )
);
/*
Test for Absence of Duplicate Tuples
15.	Find all courses that were offered at most once in 2022.
*/
SELECT course_id
FROM Section
WHERE year = 2022
GROUP BY course_id
HAVING COUNT(*) <= 1;
/*
16.	Find all the students who have opted at least two courses offered by CSE department.
*/
SELECT ID
FROM Takes
WHERE course_id IN (
    SELECT course_id
    FROM Course
    WHERE Dept_name = 'CSE'
)
GROUP BY ID
HAVING COUNT(DISTINCT course_id) >= 2;

/*
Subqueries in the From Clause
17.	Find the average instructors salary of those departments where the average salary is greater than 42000
*/

SELECT Dept_name, AVG(Salary) AS avg_salary
FROM Instructor
GROUP BY Dept_name
HAVING AVG(Salary) > 42000;
/*
Views
18.	Create a view all_courses consisting of course sections offered by Physics department in the Fall 2022, with the building and room number of each section.
*/
CREATE VIEW all_courses AS
SELECT Section.course_id, Section.building, Section.room_number
FROM Section
JOIN Course ON Section.course_id = Course.course_id
WHERE Course.Dept_name = 'Physics' AND Section.semester = 'Fall' AND Section.year = 2022;
/*
19.	Select all the courses from all_courses view.
*/

SELECT * FROM all_courses;

/*
20.	Create a view department_total_salary consisting of department name and total salary of that department.
*/
CREATE VIEW department_total_salary AS
SELECT Dept_name, SUM(Salary) AS total_salary
FROM Instructor
GROUP BY Dept_name;
