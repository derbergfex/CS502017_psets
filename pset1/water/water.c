#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Output 'Minutes: ' to the user
    printf("Minutes: ");

    // Inputs the number of minutes from the user
    int minutes = get_int();

    // In each minute, 1.5 gallons flow (or 128 ounces)
    // If we approximate each bottle to have 16 ounces, then we divide by 16
    int bottles = minutes * 1.5 * 128 / 16;
    printf("Bottles: %i\n", bottles);
}