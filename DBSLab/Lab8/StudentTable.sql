CREATE TABLE StudentTable (
 RollNo NUMBER PRIMARY KEY,
 GPA NUMBER(3, 1)
);
INSERT INTO StudentTable (RollNo, GPA) VALUES (1, 5.8);
INSERT INTO StudentTable (RollNo, GPA) VALUES (2, 6.5);
INSERT INTO StudentTable (RollNo, GPA) VALUES (3, 3.4);
INSERT INTO StudentTable (RollNo, GPA) VALUES (4, 7.8);
INSERT INTO StudentTable (RollNo, GPA) VALUES (5, 9.5);
CREATE TABLE Instructorr(
 InstructorID NUMBER PRIMARY KEY,
 Name VARCHAR2(100),
 Department VARCHAR2(100)
);
INSERT INTO Instructorr (InstructorID, Name, Department) VALUES (1, 'Dr. Smith', 'Physics');
INSERT INTO Instructorr (InstructorID, Name, Department) VALUES (2, 'Dr. Johnson', 'Mathematics');
INSERT INTO Instructorr (InstructorID, Name, Department) VALUES (3, 'Dr. Smith', 'Chemistry');
INSERT INTO Instructorr (InstructorID, Name, Department) VALUES (4, 'Dr. Evans', 'Biology');
--1
DECLARE
 v_RollNo StudentTable.RollNo%TYPE := 1;
 v_GPA StudentTable.GPA%TYPE;
BEGIN
 SELECT GPA INTO v_GPA
 FROM StudentTable
 WHERE RollNo = v_RollNo;
 IF v_GPA IS NOT NULL THEN
 DBMS_OUTPUT.PUT_LINE('GPA: ' || v_GPA);
 END IF;
END;
--2
DECLARE
 v_RollNo StudentTable.RollNo%TYPE := 1;
 v_GPA StudentTable.GPA%TYPE;
 v_Grade VARCHAR2(2);
BEGIN
 SELECT GPA INTO v_GPA
 FROM StudentTable
 WHERE RollNo = v_RollNo;
 IF v_GPA BETWEEN 0 AND 4 THEN
 v_Grade := 'F';
 ELSIF v_GPA BETWEEN 4 AND 5 THEN
 v_Grade := 'E';
 ELSIF v_GPA BETWEEN 5 AND 6 THEN
 v_Grade := 'D';
 ELSIF v_GPA BETWEEN 6 AND 7 THEN
 v_Grade := 'C';
 ELSIF v_GPA BETWEEN 7 AND 8 THEN
 v_Grade := 'B';
 ELSIF v_GPA BETWEEN 8 AND 9 THEN
 v_Grade := 'A';
 ELSE
 v_Grade := 'A+';
 END IF;
 DBMS_OUTPUT.PUT_LINE('Grade: ' || v_Grade);
END;
--3
DECLARE
 v_DateIssue DATE := TO_DATE('2025-03-01', 'YYYY-MM-DD');
 v_DateReturn DATE := TO_DATE('2025-03-20', 'YYYY-MM-DD');
 v_DaysLate NUMBER;
 v_Fine NUMBER := 0;
BEGIN
 v_DaysLate := v_DateReturn - v_DateIssue;
 IF v_DaysLate <= 7 THEN
 v_Fine := 0;
 ELSIF v_DaysLate BETWEEN 8 AND 15 THEN
 v_Fine := (v_DaysLate - 7) * 1;
 ELSIF v_DaysLate BETWEEN 16 AND 30 THEN
 v_Fine := (v_DaysLate - 15) * 2 + 8;
 ELSE
 v_Fine := (v_DaysLate - 30) * 5 + 38;
 END IF;
 DBMS_OUTPUT.PUT_LINE('Late Period: ' || v_DaysLate || ' days');
 DBMS_OUTPUT.PUT_LINE('Fine Amount: Rs. ' || v_Fine);
END;
--4
DECLARE
 v_RollNo NUMBER := 1; -- Start from RollNo 1
 v_GPA StudentTable.GPA%TYPE;
 v_Grade VARCHAR2(2);
BEGIN
 WHILE v_RollNo <= 5 LOOP
 SELECT GPA INTO v_GPA
 FROM StudentTable
 WHERE RollNo = v_RollNo;
 IF v_GPA BETWEEN 0 AND 4 THEN
 v_Grade := 'F';
 ELSIF v_GPA BETWEEN 4 AND 5 THEN
 v_Grade := 'E';
 ELSIF v_GPA BETWEEN 5 AND 6 THEN
 v_Grade := 'D';
 ELSIF v_GPA BETWEEN 6 AND 7 THEN
 v_Grade := 'C';
 ELSIF v_GPA BETWEEN 7 AND 8 THEN
 v_Grade := 'B';
 ELSIF v_GPA BETWEEN 8 AND 9 THEN
 v_Grade := 'A';
 ELSE
 v_Grade := 'A+';
 END IF;
 DBMS_OUTPUT.PUT_LINE('Roll No: ' || v_RollNo || ' - Grade: ' || v_Grade);
 v_RollNo := v_RollNo + 1;
 END LOOP;
END;
--5
ALTER TABLE StudentTable ADD LetterGrade VARCHAR2(2);
DECLARE
 v_RollNo NUMBER := 1; -- Start with RollNo 1
 v_GPA StudentTable.GPA%TYPE;
 v_Grade VARCHAR2(2);
BEGIN
 WHILE v_RollNo <= 5 LOOP
 SELECT GPA INTO v_GPA
 FROM StudentTable
 WHERE RollNo = v_RollNo;
 IF v_GPA BETWEEN 0 AND 4 THEN
 v_Grade := 'F';
 ELSIF v_GPA BETWEEN 4 AND 5 THEN
 v_Grade := 'E';
 ELSIF v_GPA BETWEEN 5 AND 6 THEN
 v_Grade := 'D';
 ELSIF v_GPA BETWEEN 6 AND 7 THEN
 v_Grade := 'C';
 ELSIF v_GPA BETWEEN 7 AND 8 THEN
 v_Grade := 'B';
 ELSIF v_GPA BETWEEN 8 AND 9 THEN
 v_Grade := 'A';
 ELSE
 v_Grade := 'A+';
 END IF;
 UPDATE StudentTable
 SET LetterGrade = v_Grade
 WHERE RollNo = v_RollNo;
 v_RollNo := v_RollNo + 1; -- Move to the next RollNo
 END LOOP;
 DBMS_OUTPUT.PUT_LINE('Letter grades updated successfully.');
END;
6
BEGIN
 FOR v_RollNo IN 1..5 LOOP
 UPDATE StudentTable
 SET LetterGrade =
 CASE
 WHEN GPA BETWEEN 0 AND 4 THEN 'F'
 WHEN GPA BETWEEN 4 AND 5 THEN 'E'
 WHEN GPA BETWEEN 5 AND 6 THEN 'D'
 WHEN GPA BETWEEN 6 AND 7 THEN 'C'
 WHEN GPA BETWEEN 7 AND 8 THEN 'B'
 WHEN GPA BETWEEN 8 AND 9 THEN 'A'
 ELSE 'A+'
 END
 WHERE RollNo = v_RollNo;
 END LOOP;
 DBMS_OUTPUT.PUT_LINE('Letter grades updated successfully.');
END;
--7
DECLARE
 v_RollNo NUMBER := 1;
 v_MaxGPA NUMBER := -1;
 v_MaxRollNo NUMBER;
 v_GPA NUMBER;
BEGIN
 <<FindMax>>
 LOOP
 EXIT WHEN v_RollNo > 5;
 SELECT GPA INTO v_GPA
 FROM StudentTable
 WHERE RollNo = v_RollNo;
 IF v_GPA > v_MaxGPA THEN
 v_MaxGPA := v_GPA;
 v_MaxRollNo := v_RollNo;
 END IF;
 v_RollNo := v_RollNo + 1;
 END LOOP;
 DBMS_OUTPUT.PUT_LINE('Student with max GPA: RollNo ' || v_MaxRollNo || ' GPA: ' ||
v_MaxGPA);
END;
--8
DECLARE
 v_Name VARCHAR2(100) := 'Dr. Smith';
 v_Count NUMBER;
BEGIN
 SELECT COUNT(*) INTO v_Count
 FROM Instructor
 WHERE InstructorName = v_Name; -- Use the correct column name
 IF v_Count > 1 THEN
 RAISE_APPLICATION_ERROR(-20001, 'Multiple instructors found with the same name.');
 ELSIF v_Count = 0 THEN
 RAISE_APPLICATION_ERROR(-20002, 'No instructor found with the given name.');
 ELSE
 DBMS_OUTPUT.PUT_LINE('Instructor details fetched successfully.');
 END IF;
EXCEPTION
 WHEN OTHERS THEN
 DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
