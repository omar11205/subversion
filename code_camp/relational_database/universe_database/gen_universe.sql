-- Create the database
CREATE DATABASE universe;

-- Connect to the database
\c universe;

-- Create the tables
CREATE TABLE galaxy (
    galaxy_id SERIAL PRIMARY KEY,
    name VARCHAR(30) NOT NULL UNIQUE,
    minor_axis_diameter INT NOT NULL,
    shape TEXT NOT NULL,
    has_black_hole BOOLEAN NOT NULL,
    num_stars_bill INT
);

CREATE TABLE star (
    star_id SERIAL PRIMARY KEY,
    name VARCHAR(30) NOT NULL UNIQUE,
    type VARCHAR(30) NOT NULL,
    age_bill_years INT,
    is_visible BOOLEAN NOT NULL,
    galaxy_id INT REFERENCES galaxy(galaxy_id)
);

CREATE TABLE planet (
    planet_id SERIAL PRIMARY KEY,
    name VARCHAR(30) NOT NULL UNIQUE,
    diameter NUMERIC NOT NULL,
    atmosphere TEXT,
    has_life BOOLEAN NOT NULL,
    star_id INT REFERENCES star(star_id)
);

CREATE TABLE moon (
    moon_id SERIAL PRIMARY KEY,
    name VARCHAR(30) NOT NULL UNIQUE,
    distance_from_planet NUMERIC NOT NULL,
    is_inhabited BOOLEAN NOT NULL,
    planet_id INT REFERENCES planet(planet_id)
);

CREATE TABLE asteroid (
    asteroid_id SERIAL PRIMARY KEY,
    name VARCHAR NOT NULL UNIQUE,
    diameter NUMERIC NOT NULL,
    is_potentially_hazardous BOOLEAN NOT NULL,
    galaxy_id INT REFERENCES galaxy(galaxy_id)
);

-- Insert data into the tables
INSERT INTO galaxy (name, minor_axis_diameter, shape, has_black_hole, num_stars_bill) VALUES
('Milky Way', 87400, 'Spiral', TRUE, 400),
('Andromeda', 152300, 'Elliptical', TRUE, 1000),
('Triangulum', 50000, 'Irregular', FALSE, 10),
('Messier 87', 93870, 'Elliptical', TRUE, 1000),
('Whirlpool', 76900, 'Spiral', FALSE, 30),
('Sombrero', 87400, 'Spiral', FALSE, 100);

INSERT INTO star (name, type, age_bill_years, is_visible, galaxy_id) VALUES ('Sun', 'G-type', 4603, TRUE, 1), 
('Alpha Centauri', 'G-type', 5500, TRUE, 1), ('Betelgeuse', 'Red Giant', 15000, TRUE, 2), 
('Vega', 'A-type', 600, TRUE, 1), ('Sirius', 'A-type', 2750, TRUE, 1), 
('Proxima Centauri', 'M-type', 4850, TRUE, 1);

INSERT INTO planet (name, diameter, atmosphere, has_life, star_id) VALUES
('Earth', 12742, 'Nitrogen, Oxygen', TRUE, 1),
('Mars', 6779, 'Carbon Dioxide', FALSE, 1),
('Jupiter', 139822, 'Hydrogen, Helium', FALSE, 1),
('Saturn', 116464, 'Hydrogen, Helium', FALSE, 1),
('Neptune', 49528, 'Hydrogen, Helium', FALSE, 1),
('Uranus', 50724, 'Hydrogen, Helium', FALSE, 1),
('Venus', 12104, 'Carbon Dioxide', FALSE, 1),
('Mercury', 4879, 'None', FALSE, 1),
('Pluto', 2370, 'Nitrogen, Methane', FALSE, 1),
('Kepler-186f', 14424, 'Nitrogen, Oxygen', TRUE, 1),
('TRAPPIST-1d', 12200, 'Carbon Dioxide', TRUE, 1),
('HD 209458 b', 113000, 'Hydrogen, Helium', FALSE, 1);

INSERT INTO moon (name, distance_from_planet, is_inhabited, planet_id) VALUES
('Moon', 384400, FALSE, 1),
('Phobos', 9376, FALSE, 2),
('Deimos', 23463, FALSE, 2),
('Ganymede', 1070400, FALSE, 3),
('Europa', 671100, FALSE, 3),
('Io', 421800, FALSE, 3),
('Titan', 1221870, FALSE, 4),
('Rhea', 527040, FALSE, 4),
('Iapetus', 3560840, FALSE, 4),
('Triton', 354760, FALSE, 5),
('Charon', 19571, FALSE, 9),
('Dione', 377420, FALSE, 4),
('Enceladus', 238040, FALSE, 4),
('Tethys', 294660, FALSE, 4),
('Oberon', 583520, FALSE, 6),
('Miranda', 129780, FALSE, 6),
('Ariel', 190900, FALSE, 6),
('Umbriel', 266300, FALSE, 6),
('Titania', 436300, FALSE, 6),
('Callisto', 1882700, FALSE, 3);

INSERT INTO asteroid (name, diameter, is_potentially_hazardous, galaxy_id) VALUES
('Apophis', 370, TRUE, 2),
('Bennu', 492, TRUE, 1),
('Ceres', 939, FALSE, 1),
('Vesta', 525, FALSE, 1),
('Eros', 34, FALSE, 1),
('Gaspra', 19, FALSE, 1),
('Ida', 31, FALSE, 1),
('Mathilde', 52, FALSE, 1),
('Kleopatra', 135, FALSE, 1),
('Psyche', 226, FALSE, 1);

-- Check the data in the tables
SELECT * FROM galaxy;
SELECT * FROM star;
SELECT * FROM planet;
SELECT * FROM moon;