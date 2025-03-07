-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Checking description of the crime report for the theft in the bakery
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7;

-- Checking the Transcript of the interviews mentioned in the description
SELECT transcript FROM interviews
WHERE day = 28 AND month = 7
AND transcript LIKE "%bakery%";

-- Checking bakery parking lot security footage as mentioned by the first witness
SELECT bakery_security_logs.license_plate, people.name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.day = 28 AND bakery_security_logs.month = 7
AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25;

-- Checking atm transactions and name of people who were withdrawing money as mentioned by the second witness
SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE day =28 AND month =7 AND atm_location = "Leggett Street"));

-- 
