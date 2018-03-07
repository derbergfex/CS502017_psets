// Libraries that includes functions to be used
#include <cs50.h>
#include <stdio.h>

// Declares the function before getting used
void say (string s,int n);

// Main playground
int main (void)
{
    printf("Height: ");
    int height = get_int();

    // If it had failed to satisfy the given condition, promt again
    while (height > 23 || height < 0)
    {
        printf("Height: ");
        height = get_int();
    }

    // Below are a list of functions to execute accordingly to obtain the required order
    for (int j = 1; j <= height; j++)
    {
        say(" ", height - j);
        say("#", j);
        printf("  ");
        say("#", j);
        printf("\n");
    }
}

// A function that prints string s n times
void say (string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", s);
    }
}

