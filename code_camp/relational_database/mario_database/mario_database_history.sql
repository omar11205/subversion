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
--To know what row is for a character, you need to set a foreign key so you can relate rows from this table to rows from your characters table. 
ALTER TABLE more_info  ADD PRIMARY KEY(more_info_id);
ALTER TABLE more_info ADD COLUMN birthday DATE;
ALTER TABLE more_info ADD COLUMN height INT;

--decimal data type
--NUMERIC(4, 1) has up to four digits and one of them has to be to the right of the decimal
ALTER TABLE more_info ADD COLUMN weight NUMERIC(4, 1);

--foreign key creation
--To know what ros is for a character, you need to set a foreign key so you can relate rows from this table to rows from tyour characters table.
ALTER TABLE more_info ADD COLUMN character_id INT REFERENCES characters(character_id);

--making one to one relation between the tables
ALTER TABLE more_info ADD UNIQUE(character_id);

--making NOT NULL 
ALTER TABLE more_info ALTER COLUMN character_id SET NOT NULL;

--what character_id you need for the foreign key column?
SELECT character_id FROM characters;
SELECT character_id, name FROM characters;

--adding information starting with mario id=1
INSERT INTO more_info(birthday, height, weight, character_id) VALUES('1981-07-09', 155, 64.5, 1);
INSERT INTO more_info(birthday, height, weight, character_id) VALUES('1983-07-14', 175, 48.8, 2);
INSERT INTO more_info(birthday, height, weight, character_id) VALUES('1985-10-18', 173, 52.2, 3);
SELECT character_id, name FROM characters WHERE name='Toad';
INSERT INTO more_info(birthday, height, weight, character_id) VALUES('1950-01-10', 66, 35.6, 4);
SELECT character_id, name FROM characters WHERE name='Bowser';
SELECT character_id, name FROM characters WHERE name='Daisy';
INSERT INTO more_info(birthday, height, weight, character_id) VALUES('1989-07-31', NULL, NULL, 6);
INSERT INTO more_info(birthday, height, weight, character_id) VALUES('1990-04-13', 162, 59.1, 7);

--hits for units
ALTER TABLE more_info RENAME COLUMN height TO height_in_cm;
ALTER TABLE more_info RENAME COLUMN weight TO weight_in_kg;

--creating sounds table
CREATE TABLE sounds(sound_id SERIAL PRIMARY KEY);
ALTER TABLE sounds  ADD COLUMN filename VARCHAR(40) NOT NULL UNIQUE;

--one-to-many foreign KEY because one character will have many sounds, but no sound will have more than one character
ALTER TABLE sounds ADD COLUMN character_id INT NOT NULL REFERENCES characters(character_id);
SELECT * FROM characters ORDER BY character_id;

--fill the sounds
INSERT INTO sounds(filename, character_id) VALUES('its-a-me.wav', 1);
INSERT INTO sounds(filename, character_id) VALUES('yippee.wav', 1);
INSERT INTO sounds(filename, character_id) VALUES('ha-ha.wav', 2);
INSERT INTO sounds(filename, character_id) VALUES('oh-yeah.wav', 2);
INSERT INTO sounds(filename, character_id) VALUES('yay.wav', 3), ('woo-hoo.wav', 3);
INSERT INTO sounds(filename, character_id) VALUES('mm-hmm.wav', 3), ('yahoo.w
av', 1);

--create table actions
CREATE TABLE actions(action_id SERIAL PRIMARY KEY);
ALTER TABLE actions ADD COLUMN action VARCHAR(20) UNIQUE NOT NULL;

--the actions table won't have any foreign keys. It's going to have a "many-to-many" relationship with the characters table. This is because many of the characters can perform many actions
INSERT INTO actions(action) VALUES('run');
INSERT INTO actions(action) VALUES('jump');
INSERT INTO actions(action) VALUES('duck');

--Many-to-many relationships usually use a juction table to link two tables together, forming two "one-to-many" relationships. Your characters and anctions table will be linked using a junction table
CREATE TABLE character_actions();
--Your junction table will use the primary keys from the characters and actions tables as foreign keys to create the relationship
ALTER TABLE character_actions ADD COLUMN character_id INT NOT NULL;
--create first foreign key to characters table
ALTER TABLE character_actions ADD FOREIGN KEY(character_id) REFERENCES characters(character_id);
ALTER TABLE character_actions ADD COLUMN action_id INT NOT NULL;
ALTER TABLE character_actions ADD FOREIGN KEY(action_id) REFERENCES actions(action_id);

--creating a composite primary key: primary key for two columns
ALTER TABLE character_actions ADD PRIMARY KEY(character_id, action_id);
--This table will have multiple rows with the same character_id, and multiple rows the same action_id. So neither of them are unique. But you never have the same character_id and action_id in a sigle row. So the two columns together can be used to uniquely identify each row.

--filling character_actions
INSERT INTO character_actions(character_id, action_id) VALUES(7,1), (7,2), (7,3); 
INSERT INTO character_actions(character_id, action_id) VALUES(6,1), (6,2), (6,3);
INSERT INTO character_actions(character_id, action_id) VALUES(5,1), (5,2), (5,3);
INSERT INTO character_actions(character_id, action_id) VALUES(4,1), (4,2), (4,3);
INSERT INTO character_actions(character_id, action_id) VALUES(3,1), (3,2), (3,3);
INSERT INTO character_actions(character_id, action_id) VALUES(2,1), (2,2), (2,3);
INSERT INTO character_actions(character_id, action_id) VALUES(1,1), (1,2), (1,3);

--FULL JOIN for see foreig key related tables
--characters with more_info
SELECT * FROM characters FULL JOIN more_info ON characters.character_id = more_info.character_id;
--characters with sounds
SELECT * FROM characters FULL JOIN sounds ON characters.character_id = sounds.character_id;
--one to many relationship

