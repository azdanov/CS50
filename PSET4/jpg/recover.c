/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FILE_NAME "card.raw"

typedef struct
{
    uint8_t first_byte;
    uint8_t second_byte;
    uint8_t third_byte;
    uint8_t fourth_byte;
} JPG_HEAD;


int main(void)
{
    int namingHelper = 0;
    char jpegName[8];
    FILE* jpeg = NULL;

    // Open card.raw image
    FILE* card = fopen(FILE_NAME, "r");
    if (card == NULL)
    {
        fprintf(stderr, "Could not open %s\n", FILE_NAME);
        perror("");
        return 1;
    }

    while (card)
    {
        // New storage
        JPG_HEAD jpg;
        uint8_t block[508];

        // Read in the 512 bytes
        fread(&jpg, sizeof(JPG_HEAD), sizeof(uint8_t), card);
        fread(block, sizeof(block), sizeof(uint8_t), card);

        // Check for end of card file
        if (feof(card))
            break;

        // Verify JPG Header
        if (jpg.first_byte == 0xFF && jpg.second_byte == 0xD8 && jpg.third_byte == 0xFF &&
            (jpg.fourth_byte >= 0xE0 && jpg.fourth_byte <= 0xEF))
        {
            if (jpeg)
            {
                fclose(jpeg);
                jpeg = NULL;
            }

            // Set a new name for a jpg file
            sprintf(jpegName, "%.3d.jpg", namingHelper++);

            // Open a new jpg
            jpeg = fopen(jpegName, "w");
            if (jpeg == NULL)
            {
                fprintf(stderr, "Could not create %s\n", jpegName);
                perror("");
                exit(2);
            }
        }
        // Write to a jpg file
        if (jpeg)
        {
            fwrite(&jpg, sizeof(JPG_HEAD), sizeof(uint8_t), jpeg);
            fwrite(block, sizeof(block), sizeof(uint8_t), jpeg);
        }
    }

    fclose(card);
    fclose(jpeg);

    return 0;
}