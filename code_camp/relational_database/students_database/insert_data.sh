#!/bin/bash

# Script to insert data from courses.csv and students.csv into students database
# while read MAJOR COURSE: "mientreas lea courses.csv leer MAJOR y COURSE" se crean las variables MAJOR Y COURSE
# a MAJOR se le asigna la primera palalabra y a COURSE la segunda
cat courses.csv | while read MAJOR COURSE
do 
  echo $MAJOR
done

# para hacer que se le asigne la primera frase completa a MAJOR y a COURSE EL Internal field separator debe ser ","

cat courses.csv | while IFS="," read MAJOR COURSE
do 
  echo $MAJOR $COURSE
done

# planeación del script para rellenado automático

cat courses.csv | while IFS="," read MAJOR COURSE
do
  # get major_id

  # if not found

  # insert major

  # get new major_id

  # get course_id

  # if not found

  # insert course

  # get new course_id

  #insert into majors_courses
  
done