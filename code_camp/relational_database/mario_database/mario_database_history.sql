-- list all databases
\l

-- list all child elements 
\d 

CREATE DATABASE first_database;
CREATE TABLE second_table();

--connect to database second_database
c\ second_database;
 
--VARCHAR: short string of characters VARCHAR(30)
\d second_table;
ALTER TABLE second_table ADD COLUMN name VARCHAR(30);
ALTER TABLE second_table RENAME COLUMN name TO username;
INSERT INTO second_table(id, username) VALUES(1, 'Samus');

--QUERYS
SELECT columns FROM table_name
SELECT * FROM second_table;

--deleting a ROW
DELETE FROM table_name WHERE condition;
DELETE FROM second_table WHERE username='Luigi';

--deleting a table
DROP TABLE table_name;
DROP TABLE second_table;

--rename a database
ALTER DATABASE first_database RENAME TO mario_database;

--Delete database
DROP DATABASE second_database;

--create new table
CREATE TABLE characters();

--SERIAL: INT with NOT NULL constraint and automatically increment
ALTER TABLE characters ADD COLUMN character_id SERIAL;
ALTER TABLE characters ADD COLUMN name VARCHAR(30) NOT NULL;
ALTER TABLE characters ADD COLUMN homeland  VARCHAR(60);
ALTER TABLE characters ADD COLUMN favorite_color VARCHAR(30);

--adding rows
INSERT INTO characters(name, homeland, favorite_color) VALUES('Mario', 'Mushroom Kingdom', 'Red');
--automatically starts WITH 1, not with O
SELECT * FROM characters; 
INSERT INTO characters(name, homeland, favorite_color) VALUES('Luigi', 'Mushroom Kingdom', 'Green');
INSERT INTO characters(name, homeland, favorite_color) VALUES('Peach', 'Mushroom Kingdom', 'Pink');

--for mulple addigs
INSERT INTO characters(name, homeland, favorite_color) VALUES('Toadstool', 'Mushroom Kingdom', 'Red'), ('Bowser', 'Mushroom Kingdom', 'Green');
INSERT INTO characters(name, homeland, favorite_color) VALUES('Daisy', 'Sarasaland', 'Yellow'), ('Yoshi', 'Dinosaur Land', 'Green');

UPDATE characters SET character_id=4 WHERE character_id = 11;
UPDATE characters SET favorite_color='Orange' WHERE name='Daisy';
UPDATE characters SET name='Toad' WHERE favorite_color='Red';
UPDATE characters SET name='Mario' WHERE character_id=1;
UPDATE characters SET favorite_color='Blue' WHERE character_id=4;
UPDATE characters SET homeland='Koopa Kingdom' WHERE character_id=5;

--ordering database
SELECT * FROM characters ORDER BY character_id;

--add a primary key (unique for each table)
ALTER TABLE characters ADD PRIMARY KEY(name);

--how to drop a constraint
ALTER TABLE characters DROP CONSTRAINT characters_pkey;

--settin the right primary key
ALTER TABLE characters ADD PRIMARY KEY(character_id);

--create a new table
CREATE TABLE more_info();
ALTER TABLE more_info ADD COLUMN more_info_id SERIAL;
ALTER TABLE more_info  ADD PRIMARY KEY(more_info_id);
ALTER TABLE more_info ADD COLUMN birthday DATE;
ALTER TABLE more_info ADD COLUMN height INT;

--decimal data type
--NUMERIC(4, 1) has up to four digits and one of them has to be to the right of the decimal
ALTER TABLE more_info ADD COLUMN weight NUMERIC(4, 1);