#include <stdio.h>
#include <stdint.h>
typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // check proper use
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");

    // check if cannot open file
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    int count = 0;
    BYTE buffer[512];
    int inJPEG = 0;
    FILE *img = NULL;

    // if the the current B isn't empty
    while (fread(&buffer, 1, sizeof(buffer), inptr) == 512)
    {
        // if conditions are met, we've found a new JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if we're already in a JPEG
            if (inJPEG == 1)
            {
                fclose(img);
            }
            else
            {
                // signifies that we found a JPEG
                inJPEG = 1;
            }

            // we create a constant char array
            // (filename cannot be a global array to avoid buffer overflow)
            char filename[7];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }

        if (inJPEG == 1)
        {
            fwrite(&buffer, 1, sizeof(buffer), img);
        }
    }

    fclose(inptr);
    fclose(img);
    return 0;
}