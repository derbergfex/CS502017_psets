#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Error message if 'k' is not provided.
    if (argc != 2)
    {
        printf("Provide the shifting factor\n");
        return 1;
    }

    //  Prompt the user for plaintext.
    printf("plaintext: ");
    string plainText = get_string();

    // Convert k from a string to an integer via the atoi library function.
    printf("ciphertext: ");
    int k = atoi(argv[1]);

    // Check for a valid 'k'.
    if (k < 0)
    {
        printf("Provide a valid shifting factor\n");
        return 1;
    }

    // Loop through each character of the plaintext.
    for (int i = 0, n = strlen(plainText); i < n; i++)
    {

        // If the character is lowercase:
        if (islower(plainText[i]))
        {
            printf("%c", ((plainText[i] - 96 + k) % 26) + 96);
        }

        // If the character is uppercase:
        else if (isupper(plainText[i]))
        {
            printf("%c", toupper(((plainText[i] - 64 + k) % 26) + 64));
        }

        // If it's not an alphabetic letter, just return it as it is.
        else
        {
            printf("%c", plainText[i]);
        }

    }

    printf("\n");
    return 0;

}






