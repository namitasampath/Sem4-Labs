-- 1. Create the EMPLOYEE table
CREATE TABLE EMPLOYEE (
  emp_no NUMBER(3),
  emp_name VARCHAR(20),
  emp_address VARCHAR(20)
);

-- 2. Insert five employees' information
INSERT INTO EMPLOYEE (emp_no, emp_name, emp_address) VALUES (101, 'Mahika', 'Mumbai');
INSERT INTO EMPLOYEE (emp_no, emp_name, emp_address) VALUES (102, 'Namita', 'Mangalore');
INSERT INTO EMPLOYEE (emp_no, emp_name, emp_address) VALUES (103, 'Geethika', 'Bangalore');
INSERT INTO EMPLOYEE (emp_no, emp_name, emp_address) VALUES (104, 'Rishita', 'Manipal');
INSERT INTO EMPLOYEE (emp_no, emp_name, emp_address) VALUES (105, 'Hareetha', 'Chennai');

-- 3. Display names of all employees
SELECT emp_name FROM EMPLOYEE;

-- 4. Display all employees from ‘MANIPAL’
SELECT * FROM EMPLOYEE WHERE emp_address = 'Manipal';

-- 5. Add a column named salary to the EMPLOYEE table
ALTER TABLE EMPLOYEE ADD salary NUMBER(10,2);

-- 6. Assign the salary for all employees
UPDATE EMPLOYEE SET salary = 50000 WHERE emp_no = 101;
UPDATE EMPLOYEE SET salary = 55000 WHERE emp_no = 102;
UPDATE EMPLOYEE SET salary = 60000 WHERE emp_no = 103;
UPDATE EMPLOYEE SET salary = 65000 WHERE emp_no = 104;
UPDATE EMPLOYEE SET salary = 70000 WHERE emp_no = 105;

-- 7. View the structure of the EMPLOYEE table
DESC EMPLOYEE;

-- 8. Delete all employees from ‘MANGALORE’
DELETE FROM EMPLOYEE WHERE emp_address = 'Mangalore';

-- 9. Rename EMPLOYEE table to EMPLOYEE1
ALTER TABLE EMPLOYEE RENAME TO EMPLOYEE1;

-- 10. Drop the EMPLOYEE1 table
DROP TABLE EMPLOYEE1;
