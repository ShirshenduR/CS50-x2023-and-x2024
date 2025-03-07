SELECT title FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN ratings on movies.id = ratings.movie_id
WHERE rating>5.0 AND stars.person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman') ORDER BY rating DESC LIMIT 5;
