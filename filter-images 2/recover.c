#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t buffer[512];

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Other declarations
    int numberofjpegs = 0;
    char filename[8];
    FILE *currentfile;

    // While read function is seeing jpeg, "read" contents of file into buffer, open a file for each jpeg, name it, "write from buffer into new jpeg file, close file"
    // I received help from Max during a Walkthrough at office hours on Sunday Oct. 6
    while (fread(buffer, 1, 512, f) == 512)
    {
        //int bytesread = fread(buffer, 1, 512, f);

        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0)
        {
            if (numberofjpegs != 0)
            {
                fclose(currentfile);
            }
            sprintf(filename, "%03i.jpg", numberofjpegs);
            currentfile = fopen(filename, "w");
            numberofjpegs++;
        }
        // If we're in the process of writing the jpeg, continue writing to that jpeg (append 512 bytes)
        if (numberofjpegs != 0)
        {
            fwrite(buffer, 512, 1, currentfile);
        }
    }
    fclose(f);
    fclose(currentfile);
    return 0;
}

