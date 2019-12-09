#include <cs50.h>
#include <stdio.h>

int fuel_req(int mass);

int main(int argc, string argv[])
{
    int input;
    int total_fuel = 0;
    while (true)
    {
        input = get_int("");
        if (input == INT_MAX) break;
        total_fuel += fuel_req(input);
        //printf("%i\n", fuel_req(input));
    }
    printf("%i\n", total_fuel);
}

int fuel_req(int mass)
{
    return mass / 3 - 2;
}