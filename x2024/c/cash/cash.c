#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);
    int pennies = calculate_pennies(cents);
    int change = quarters + dimes + nickels + pennies;
    printf("%i\n", change);
}

int calculate_quarters(int cents)
{
    // Calculating Quarters
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculating dimes
    int dimes = 0;
    while (cents >= 10 && cents < 25)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculating nickels
    int nickels = 0;
    while (cents >= 5 && cents < 10)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculatig pennies
    int pennies = 0;
    while (cents >= 1 && cents < 5)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
