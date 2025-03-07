-- Keep a log of any SQL queries you execute as you solve the mystery.
.tables
.schema crime_scene_reports
SELECT * FROM crime_scene_reports WHERE day =28 and month = 7 and street= "Humphrey Street";
SELECT * FROM interviews WHERE day =28 and month = 7 AND transcript LIKE "%bakery%";
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day=28 AND hour =10 and month= 7 and minute >15 and activity ="exit"); -- suspects
--1st step
SELECT * FROM bank_accounts WHERE person_id IN (SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day=28 AND hour =10 and month= 7 and minute >15 and activity ="exit"));
--2nd step
SELECT * FROM atm_transactions WHERE day=28 AND month =7 and atm_location="Leggett Street" and account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN (SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day=28 AND hour =10 and month= 7 and minute >15 and activity ="exit")));


