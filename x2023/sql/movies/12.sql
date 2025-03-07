SELECT title FROM movies
JOIN stars on movies.id = stars.movie_id
WHERE stars.person_id in (SELECT id FROM people WHERE name = 'Bradley Cooper')
AND title IN
(SELECT title FROM movies
JOIN stars on movies.id = stars.movie_id
WHERE stars.person_id in (SELECT id FROM people WHERE name ='Jennifer Lawrence'));
