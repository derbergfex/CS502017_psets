#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();

    // Convert the first letter to uppercase and print it.
    printf("%c", toupper(name[0]));

    // The letter occuring after each space is converted to uppercase and is printed.
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }

    // A new-line command to move the prompt to a new line.
    printf("\n");
}







