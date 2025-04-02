CREATE TABLE Employee (
Ssn VARCHAR(15) PRIMARY KEY,
Fname VARCHAR(50) NOT NULL,
Minit CHAR(1),
Lname VARCHAR(50) NOT NULL,
Bdate DATE,
Address VARCHAR(255),
Salary DECIMAL(10,2),
Sex CHAR(1) CHECK (Sex IN ('M', 'F'))
);

CREATE TABLE Department (
Num INT PRIMARY KEY,
Name VARCHAR(100) UNIQUE NOT NULL,
Location VARCHAR(255) NOT NULL);

CREATE TABLE Works_For (
Employee_Ssn VARCHAR(15),
Department_Number INT,
Start_date DATE,
PRIMARY KEY (Employee_Ssn, Department_Number),
FOREIGN KEY (Employee_Ssn) REFERENCES Employee(Ssn) ON DELETE CASCADE,
FOREIGN KEY (Department_Number) REFERENCES Department(Num) ON DELETE
SET NULL
);

CREATE TABLE Manages (
    Employee_Ssn VARCHAR(15),
    Department_Number INT,
    PRIMARY KEY (Employee_Ssn, Department_Number),
    FOREIGN KEY (Employee_Ssn) REFERENCES Employee(Ssn) ON DELETE CASCADE,
    FOREIGN KEY (Department_Number) REFERENCES Department(Num) ON DELETE CASCADE
);

CREATE TABLE Project (
Num INT PRIMARY KEY,
Name VARCHAR(100) UNIQUE NOT NULL,
Location VARCHAR(255) NOT NULL
);

CREATE TABLE Works_On (
Employee_Ssn VARCHAR(15),
Project_Number INT,
Hours DECIMAL(5,2) CHECK (Hours >= 0),
PRIMARY KEY (Employee_Ssn, Project_Number),
FOREIGN KEY (Employee_Ssn) REFERENCES Employee(Ssn) ON DELETE CASCADE,
FOREIGN KEY (Project_Number) REFERENCES Project(Num) ON DELETE CASCADE
);

CREATE TABLE Controls (
Department_Number INT UNIQUE,
Project_Number INT UNIQUE,
PRIMARY KEY (Department_Number, Project_Number),
FOREIGN KEY (Department_Number) REFERENCES Department(Num) ON DELETE
CASCADE,
FOREIGN KEY (Project_Number) REFERENCES Project(Num) ON DELETE CASCADE
);

CREATE TABLE Supervision (
Supervisor_Ssn VARCHAR(15),
Supervisee_Ssn VARCHAR(15),
PRIMARY KEY (Supervisor_Ssn, Supervisee_Ssn),
FOREIGN KEY (Supervisor_Ssn) REFERENCES Employee(Ssn) ON DELETE CASCADE,
FOREIGN KEY (Supervisee_Ssn) REFERENCES Employee(Ssn) ON DELETE CASCADE
);

CREATE TABLE Dependent (
Employee_Ssn VARCHAR(15),
Name VARCHAR(50),
Sex CHAR(1) CHECK (Sex IN ('M', 'F')),
Birth_date DATE,
Relationship VARCHAR(50),
PRIMARY KEY (Employee_Ssn, Name),
FOREIGN KEY (Employee_Ssn) REFERENCES Employee(Ssn) ON DELETE CASCADE
);

INSERT INTO Employee (Ssn, Fname, Minit, Lname, Bdate, Address, Salary, Sex)
VALUES ('123456789', 'John', 'D', 'Doe', '05-15-1986', '123 Elm St', 75000, 'M');

INSERT INTO Department (Num, Name, Location)
VALUES (1, 'Engineering', 'New York');

INSERT INTO Works_For 
VALUES ('123456789', 1, '05-01-2023');

INSERT INTO Project (Num, Name, Location)
VALUES (101, 'AI Development', 'San Francisco');

INSERT INTO Works_On 
VALUES ('123456789', 101, 40);
BEGIN
INSERT INTO Works_For VALUES ('123456734', 1, '01-15-2023');
INSERT INTO Works_For VALUES ('987654321', 2, '06-10-2022');
INSERT INTO Works_For VALUES ('567890123', 3, '09-25-2021');
INSERT INTO Works_For VALUES ('345678901', 4, '05-30-2020');
INSERT INTO Works_For VALUES ('234567890', 5, '11-12-2019');
end;

begin
--INSERT INTO Project (Num, Name, Location) VALUES (101, 'AI Development', 'San Francisco');
INSERT INTO Project (Num, Name, Location) VALUES (102, 'Cloud Migration', 'New York');
INSERT INTO Project (Num, Name, Location) VALUES (103, 'Marketing Strategy', 'Los Angeles');
INSERT INTO Project (Num, Name, Location) VALUES (104, 'Employee Training', 'Chicago');
INSERT INTO Project (Num, Name, Location) VALUES (105, 'Budget Analysis', 'Houston');
end;

begin
INSERT INTO Works_On VALUES ('123456734', 101, 40);
INSERT INTO Works_On VALUES ('987654321', 102, 35);
INSERT INTO Works_On VALUES ('567890123', 103, 30);
INSERT INTO Works_On VALUES ('345678901', 104, 25);
INSERT INTO Works_On VALUES ('234567890', 105, 20);
end;
