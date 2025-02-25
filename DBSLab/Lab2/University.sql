CREATE TABLE Student (
    ID NUMBER(5) PRIMARY KEY,
    name VARCHAR(100),
    dept_name VARCHAR(100),
    tot_cred INT,
    FOREIGN KEY (dept_name) REFERENCES Department(dept_name)
);

CREATE TABLE Instructor (
    ID NUMBER(5) PRIMARY KEY,
    name VARCHAR(100),
    dept_name VARCHAR(100),
    salary INT,
    FOREIGN KEY (dept_name) REFERENCES Department(dept_name)
);

CREATE TABLE Course (
    course_id VARCHAR(8) PRIMARY KEY,
    title VARCHAR(50),
    dept_name VARCHAR(100),
    credits INT,
    FOREIGN KEY (dept_name) REFERENCES Department(dept_name)
);

CREATE TABLE Takes (
    ID NUMBER(5),
    course_id VARCHAR(8),
    sec_id VARCHAR(8),
    semester VARCHAR(6),
    year INT,
    grade CHAR(2),
    PRIMARY KEY (ID, course_id, sec_id, semester, year),
    FOREIGN KEY (ID) REFERENCES Student(ID),
    FOREIGN KEY (course_id) REFERENCES Course(course_id)
);

CREATE TABLE Classroom (
    building VARCHAR(15),
    room_number VARCHAR(7),
    capacity INT,
    PRIMARY KEY (building, room_number)
);

CREATE TABLE Department (
    dept_name VARCHAR(100) PRIMARY KEY,
    building VARCHAR(15),
    budget INT
);

CREATE TABLE Section (
    course_id VARCHAR(8),
    sec_id VARCHAR(8),
    semester VARCHAR(6),
    year INT,
    building VARCHAR(15),
    room_number VARCHAR(7),
    time_slot_id CHAR(4),
    PRIMARY KEY (course_id, sec_id, semester, year),
    FOREIGN KEY (course_id) REFERENCES Course(course_id),
    FOREIGN KEY (building, room_number) REFERENCES Classroom(building, room_number)
);

CREATE TABLE Teaches (
    ID NUMBER(5),
    course_id VARCHAR(8),
    sec_id VARCHAR(8),
    semester VARCHAR(6),
    year INT,
    PRIMARY KEY (ID, course_id, sec_id, semester, year),
    FOREIGN KEY (ID) REFERENCES Instructor(ID),
    FOREIGN KEY (course_id) REFERENCES Course(course_id)
);

CREATE TABLE Advisor (
    s_id NUMBER(5),
    i_id NUMBER(5),
    PRIMARY KEY (s_id),
    FOREIGN KEY (s_id) REFERENCES Student(ID),
    FOREIGN KEY (i_id) REFERENCES Instructor(ID)
);

CREATE TABLE Time_slot (
    time_slot_id CHAR(4),
    day VARCHAR(9),
    start_time VARCHAR2(8),
    end_time VARCHAR2(8),
    PRIMARY KEY (time_slot_id, day, start_time)
);


CREATE TABLE Prereq (
    course_id VARCHAR(8),
    prereq_id VARCHAR(8),
    PRIMARY KEY (course_id, prereq_id),
    FOREIGN KEY (course_id) REFERENCES Course(course_id),
    FOREIGN KEY (prereq_id) REFERENCES Course(course_id)
);
begin 
INSERT INTO Department (dept_name, building, budget) VALUES ('CSE', 'Building A', 1000000);
INSERT INTO Department (dept_name, building, budget) VALUES ('Maths', 'Building B', 800000);
INSERT INTO Department (dept_name, building, budget) VALUES ('PhySICS', 'Building C', 900000);
INSERT INTO Department (dept_name, building, budget) VALUES ('Chemistry', 'Building B', 850000);
INSERT INTO Department (dept_name, building, budget) VALUES ('Biology', 'Building C', 700000);
end;
begin
INSERT INTO Student (ID, name, dept_name, tot_cred) VALUES (1, 'Aria', 'CSE', 30);
INSERT INTO Student (ID, name, dept_name, tot_cred) VALUES (2, 'Bob', 'Maths', 40);
INSERT INTO Student (ID, name, dept_name, tot_cred) VALUES (3, 'Chris', 'PhySICS', 20);
INSERT INTO Student (ID, name, dept_name, tot_cred) VALUES (4, 'Devin', 'Chemistry', 35);
INSERT INTO Student (ID, name, dept_name, tot_cred) VALUES (5, 'Eric', 'Biology', 25);
end;
begin
INSERT INTO Instructor (ID, name, dept_name, salary) VALUES (1, 'Aradhana', 'CSE', 95000);
INSERT INTO Instructor (ID, name, dept_name, salary) VALUES (2, 'Chris', 'Maths', 75000);
INSERT INTO Instructor (ID, name, dept_name, salary) VALUES (3, 'Nichet', 'PhySICS', 65000);
INSERT INTO Instructor (ID, name, dept_name, salary) VALUES (4, 'archana', 'Chemistry', 72000);
INSERT INTO Instructor (ID, name, dept_name, salary) VALUES (5, 'Tichen', 'Biology', 38000);
end;
begin
INSERT INTO Course (course_id, title, dept_name, credits) VALUES ('CS101', 'Intro to Computer Science', 'CSE', 3);
INSERT INTO Course (course_id, title, dept_name, credits) VALUES ('MATH101', 'Calculus I', 'Maths', 4);
INSERT INTO Course (course_id, title, dept_name, credits) VALUES ('PHYS101', 'General Physics I', 'PhySICS', 4);
INSERT INTO Course (course_id, title, dept_name, credits) VALUES ('CHEM101', 'General Chemistry I', 'Chemistry', 3);
INSERT INTO Course (course_id, title, dept_name, credits) VALUES ('BIOL101', 'Intro to Biology', 'Biology', 3);
end;
begin
INSERT INTO Takes (ID, course_id, sec_id, semester, year, grade) VALUES (1, 'CS101', '01', 'FIRST', 2015, 'A');
INSERT INTO Takes (ID, course_id, sec_id, semester, year, grade) VALUES (2, 'MATH101', '01', 'FIRST', 2025, 'B');
INSERT INTO Takes (ID, course_id, sec_id, semester, year, grade) VALUES (3, 'PHYS101', '01', 'FIRST', 2017, 'A');
INSERT INTO Takes (ID, course_id, sec_id, semester, year, grade) VALUES (4, 'CHEM101', '01', 'FIRST', 2024, 'C');
INSERT INTO Takes (ID, course_id, sec_id, semester, year, grade) VALUES (5, 'BIOL101', '01', 'FIRST', 2015, 'B');
end;
begin
INSERT INTO Classroom (building, room_number, capacity) VALUES ('BuildingA', '101', 50);
INSERT INTO Classroom (building, room_number, capacity) VALUES ('BuildingB', '102', 40);
INSERT INTO Classroom (building, room_number, capacity) VALUES ('BuildingC', '103', 30);
INSERT INTO Classroom (building, room_number, capacity) VALUES ('BuildingD', '104', 35);
INSERT INTO Classroom (building, room_number, capacity) VALUES ('BuildingE', '105', 45);
end;
begin
INSERT INTO Section (course_id, sec_id, semester, year, building, room_number, time_slot_id) VALUES ('CS101', '01', 'Fall', 2023, 'BuildingA', '101', 'A1');
INSERT INTO Section (course_id, sec_id, semester, year, building, room_number, time_slot_id) VALUES ('MATH101', '01', 'Fall', 2023, 'BuildingB', '302', 'A2');
INSERT INTO Section (course_id, sec_id, semester, year, building, room_number, time_slot_id) VALUES ('PHYS101', '01', 'Fall', 2023, 'BuildingC', '303', 'A3');
INSERT INTO Section (course_id, sec_id, semester, year, building, room_number, time_slot_id) VALUES ('CHEM101', '01', 'Fall', 2023, 'BuildingD', '204', 'A4');
INSERT INTO Section (course_id, sec_id, semester, year, building, room_number, time_slot_id) VALUES ('BIOL101', '01', 'Fall', 2023, 'BuildingE', '205', 'A5');
end;
begin
INSERT INTO Teaches (ID, course_id, sec_id, semester, year) VALUES (1, 'CS101', '01', 'SPRING', 2015);
INSERT INTO Teaches (ID, course_id, sec_id, semester, year) VALUES (2, 'MATH101', '01', 'SPRING', 2025);
INSERT INTO Teaches (ID, course_id, sec_id, semester, year) VALUES (3, 'PHYS101', '01', 'SPRING', 2017);
INSERT INTO Teaches (ID, course_id, sec_id, semester, year) VALUES (4, 'CHEM101', '01', 'SPRING', 2024);
INSERT INTO Teaches (ID, course_id, sec_id, semester, year) VALUES (5, 'BIOL101', '01', 'SPRING', 2009);
end;
begin
INSERT INTO Advisor (s_id, i_id) VALUES (1, 1);
INSERT INTO Advisor (s_id, i_id) VALUES (2, 2);
INSERT INTO Advisor (s_id, i_id) VALUES (3, 3);
INSERT INTO Advisor (s_id, i_id) VALUES (4, 4);
INSERT INTO Advisor (s_id, i_id) VALUES (5, 5);
end;
begin
INSERT INTO Time_slot (time_slot_id, day, start_time, end_time) VALUES ('A1', 'Monday', '09:00:00', '10:00:00');
INSERT INTO Time_slot (time_slot_id, day, start_time, end_time) VALUES ('A2', 'Tuesday', '10:00:00', '11:00:00');
INSERT INTO Time_slot (time_slot_id, day, start_time, end_time) VALUES ('A3', 'Wednesday', '11:00:00', '12:00:00');
INSERT INTO Time_slot (time_slot_id, day, start_time, end_time) VALUES ('A4', 'Thursday', '12:00:00', '13:00:00');
INSERT INTO Time_slot (time_slot_id, day, start_time, end_time) VALUES ('A5', 'Friday', '13:00:00', '14:00:00');
end;
begin
INSERT INTO Prereq (course_id, prereq_id) VALUES ('CS101', 'MATH101');
INSERT INTO Prereq (course_id, prereq_id) VALUES ('PHYS101', 'MATH101');
INSERT INTO Prereq (course_id, prereq_id) VALUES ('CHEM101', 'MATH101');
INSERT INTO Prereq (course_id, prereq_id) VALUES ('BIOL101', 'CHEM101');
INSERT INTO Prereq (course_id, prereq_id) VALUES ('CS101', 'PHYS101');
end;
