/*
Consider the following schema: 
Employee (EmpNo, EmpName, Gender, Salary, Address, DNo) 
Department (DeptNo, DeptName, Location) 
1. Create Employee table with following constraints: 
• Make EmpNo as Primary key. 
• Do not allow EmpName, Gender, Salary and Address to have null values. 
• Allow Gender to have one of the two values: ‘M’, ‘F’. 
*/

create table Employee (EmpNo int primary key, 
EmpName varchar(20) NOT NULL,
Gender char(1) not null check (Gender in('M','F')),
Salary decimal(10,2) not null,
Address varchar(50) not null,
Dno int);

/*
2. Create Department table with following: 
• Make DeptNo as Primary key 
• Make DeptName as candidate key
*/

create table Department(
DeptNo int primary key, 
DeptName varchar(20)not null unique,
Location varchar(20));

/*
3. Make DNo of Employee as foreign key which refers to DeptNo of Department. 
*/

ALTER TABLE Employee
ADD CONSTRAINT FK_Employee_Department
FOREIGN KEY (DNo) REFERENCES Department(DeptNo);

/*
4. Insert few tuples into Employee and Department which satisfies the above constraints. 
*/
INSERT INTO Department (DeptNo, DeptName, Location) VALUES(1, 'Comp Sc', 'Montreal');
INSERT INTO Department (DeptNo, DeptName, Location) VALUES(2, 'History', 'Ottawa');
INSERT INTO Department (DeptNo, DeptName, Location) VALUES(3, 'Data Sc', 'Toronto');

INSERT INTO Employee (EmpNo, EmpName, Gender, Salary, Address, DNo) VALUES(101, 'Kalvin', 'M', 200000.00, '123 abc St', 1);
INSERT INTO Employee (EmpNo, EmpName, Gender, Salary, Address, DNo) VALUES(102, 'Carlton', 'M', 80000.00, '456 def St', 2);
INSERT INTO Employee (EmpNo, EmpName, Gender, Salary, Address, DNo) VALUES(103, 'Tanya', 'F', 70000.00, '789 ghi St', 3);


/*
5. Try to insert few tuples into Employee and Department which violates some of the 
above constraints. 
*/
INSERT INTO Department (DeptNo, DeptName, Location) VALUES(1, 'Comp Sc', 'Scarborough');
INSERT INTO Employee (EmpNo, EmpName, Gender, Salary, Address, DNo) VALUES(105, 'Bob Brown', 'X', 90000.00, '202 Maple St', 2);

/*
6. Try to modify/delete a tuple which violates a constraint. 
(Ex: Drop a department tuple which has one or more employees)
*/

DELETE FROM Department where DeptNo=2;
--integrity constraint (DS_235816126.FK_EMPLOYEE_DEPARTMENT) violated - child record found
