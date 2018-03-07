#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Error message if 'k' is not provided.
    if (argc != 2)
    {
        printf("Provide the keyword\n");
        return 1;
    }

    // Save the keyword as a string called 'keyword'.
    string keyword = argv[1];
    int keylen = strlen(keyword);

    // Check if keyword exists.
    if (keylen == 0)
    {
        printf("Provide a valid keyword.\n");
        return 1;
    }

    // Check for non-aplhabetical characters in the keyword.
    for (int i = 0; i < keylen; i++)
    {
        if (keyword[i] > 122 || keyword[i] < 65)
        {
            printf("ERROR: only alphabetical letters are valid.\n");
            return 1;
        }
    }


    //  Prompt the user for plaintext.
    printf("plaintext: ");
    string plainText = get_string();

    printf("ciphertext: ");

    // Loop through each character of the plaintext.
    for (int i = 0, plainlen = strlen(plainText); i < plainlen; i++)
    {
        // Enable k to be reused cyclically.
        int k = keyword[i % keylen];

        // If k is a lowercase letter, we assign it to its respective value between 0 and 25 of lowercase letters.
        if (islower(k))
        {
            k -= 97;
        }

        // If k is an uppercase letter, we assign it to its respective value between 0 and 25 of uppercase letters.
        else if (isupper(k))
        {
            k -= 65;
        }

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