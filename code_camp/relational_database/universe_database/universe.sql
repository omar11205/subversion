CREATE DATABASE universe;
CREATE TABLE galaxy(galaxy_id SERIAL PRIMARY KEY);
CREATE TABLE star(star_id SERIAL PRIMARY KEY); 
CREATE TABLE planet(planet_id SERIAL PRIMARY KEY);
CREATE TABLE moon(moon_id SERIAL PRIMARY KEY);
--+1 not null
ALTER TABLE galaxy ADD COLUMN name VARCHAR(30) NOT NULL;
ALTER TABLE star ADD COLUMN name VARCHAR(30) NOT NULL;
ALTER TABLE planet ADD COLUMN name VARCHAR(30) NOT NULL;
ALTER TABLE moon ADD COLUMN name VARCHAR(30) NOT NULL;

--two INT columns
ALTER TABLE galaxy ADD COLUMN distance_from_earth_mlyl INT NOT NULL; --millions of light years
ALTER TABLE galaxy ADD COLUMN year_discovery INT NOT NULL;

--tables for stars
ALTER TABLE star ADD COLUMN distance_from_earth_mlyl INT NOT NULL; --millions of light years

ALTER TABLE planet ADD COLUMN distance_from_star_mlkm INT NOT NULL; --millons of kilometers
ALTER TABLE planet ADD COLUMN number_satelites INT NOT NULL; --millons of kilometers

ALTER TABLE moon ADD COLUMN distance_from_planet_mkm INT NOT NULL; --miles of kilometers
ALTER TABLE moon ADD COLUMN year_discovery INT NOT NULL;
