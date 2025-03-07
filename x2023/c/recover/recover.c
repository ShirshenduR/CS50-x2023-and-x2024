#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE; // defining byte
int main(int argc, char *argv[])
{
    if (argc != 2) // wrong usage condition
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not find %s\n", argv[1]); // if file not found condition
        return 10;
    }
    FILE *img = NULL; // initializing new image file
    int jpeg = 0;
    char filename[8] = {0};
    BYTE buffer[512];
    while (file != NULL)
    {

        while (fread(&buffer, sizeof(BYTE) * 512, 1, file) == 1)
        {

            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0) // checking if start of jpg
            {
                if (img != NULL) // condition for next jpg
                {
                    fclose(img);
                }
                sprintf(filename, "%03i.jpg", jpeg++);

                img = fopen(filename, "w");
            }
            if (img != NULL) // writing till start of new jpeg
            {
                fwrite(&buffer, sizeof(BYTE) * 512, 1, img);
            }
        }
        if (img != NULL) // condition for last jpeg i.e 049.jpg
        {
            fclose(img);
        }
        fclose(file);
        return 0;
    }
}