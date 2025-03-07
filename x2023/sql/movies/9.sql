SELECT name FROM people WHERE id in (SELECT person_id from stars WHERE movie_id in (SELECT id FROM movies WHERE year = 2004)) ORDER BY birth;
