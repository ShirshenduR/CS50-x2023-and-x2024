SELECT AVG(energy) as average_energy from songs WHERE artist_id= (SELECT id FROM artists WHERE name ='Drake');
