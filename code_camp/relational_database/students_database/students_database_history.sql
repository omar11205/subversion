CREATE DATABASE students;
\c students;
CREATE TABLE students();
CREATE TABLE majors();
CREATE TABLE courses();

--create a join table for majors and courses
CREATE TABLE majors_courses();

--students.csv has four fields, make a column for each of those as well as an ID column with serials for '_id's and a primary key
ALTER TABLE students ADD COLUMN student_id SERIAL;
ALTER TABLE students DROP COLUMN student_id;
ALTER TABLE students ADD COLUMN student_id SERIAL PRIMARY KEY;
ALTER TABLE students ADD COLUMN first_name VARCHAR(50) NOT NULL;
ALTER TABLE students ADD COLUMN last_name VARCHAR(50) NOT NULL;

--column for the mayor as a foreign key that references it
ALTER TABLE students ADD COLUMN  major_id INT;

--For decimals with a length of 2 and 1
ALTER TABLE students ADD COLUMN gpa NUMERIC(2,1);

--add a primary key to the majors table
ALTER TABLE majors ADD COLUMN major_id SERIAL PRIMARY KEY;

--column for the name of the major
ALTER TABLE majors ADD COLUMN major VARCHAR(50) NOT NULL;

--setting the major_id column FROM the students table as a foreign key that references the major_id column from the majors table.
ALTER TABLE students ADD FOREIGN KEY(major_id) REFERENCES majors(major_id);

--design courses table
ALTER TABLE courses ADD COLUMN course_id SERIAL PRIMARY KEY;
ALTER TABLE courses ADD COLUMN course VARCHAR(100) NOT NULL;

--desigh majors_courses junction table
ALTER TABLE majors_courses ADD COLUMN major_id INT;
ALTER TABLE majors_courses ADD COLUMN course_id INT;

--setting major_id column as a foreign key that references major_id column from majors table
ALTER TABLE majors_courses ADD FOREIGN KEY(major_id) REFERENCES majors(major_id);

--setting course_id column as a foreign key that references course_id column from courses table
ALTER TABLE majors_courses ADD FOREIGN KEY(course_id) REFERENCES courses(course_id);

--There's one thing missing. This table doesn't have a primary key. The data from courses.csv will go in this table. A single major will be in it multiple times, and same with a course. So neither of them can be a primary key. But there will never be a row with the same two values as another row. So the two columns together, are unique. You can create a composite primary key that uses more than one column as a unique pair like this: ALTER TABLE <table_name> ADD PRIMARY KEY(<column_name>, <column_name>); Add a composite primary key to the table using the two columns.
ALTER TABLE majors_courses ADD PRIMARY KEY(major_id, course_id);

--filling majors/courses table from courses.csv
INSERT INTO majors(major) VALUES('Database Administration');
INSERT INTO courses(course) VALUES('Data Structures and Algorithms');

--filling majors_courses table
INSERT INTO majors_courses(major_id, course_id) VALUES(1,1);

--filling students table
INSERT INTO students(first_name, last_name, major_id, gpa) VALUES('Rhea', 'Kellems', 1, 2.5);