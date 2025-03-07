#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./recover FILE");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not find %s\n", argv[1]);
        return 1;
    }
    FILE *img = NULL; // initializing new image file
    int jpeg = 0;
    char filename[8] = {0};
    uint8_t buffer[512];
    while (card != NULL)
    {

        while (fread(&buffer, 512, 1, card) == 1)
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
                fwrite(&buffer, 512, 1, img);
            }
        }
        if (img != NULL) // condition for last jpeg i.e 049.jpg
        {
            fclose(img);
        }
        fclose(card);
        return 0;
    }
}
