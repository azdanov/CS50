#include <stdio.h>

#define BLOCK 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *image_name = argv[1];

    FILE *file_p = fopen(image_name, "r");
    if (file_p == NULL) {
        fprintf(stderr, "Could not open %s.\n", image_name);
        return 2;
    }

    char photo_name[] = "###.jpg";
    BYTE buffer[BLOCK];
    int photo_number = 0;
    FILE *photo_p = NULL;

    for (;;) {
        fread(buffer, 1, BLOCK, file_p);

        if (feof(file_p)) {
            break;
        }

        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) {

            if (photo_p) {
                fclose(photo_p);
            }

            sprintf(photo_name, "%.3d.jpg", photo_number++);
            photo_p = fopen(photo_name, "w");
            if (photo_p == NULL) {
                fprintf(stderr, "Could not save %s.\n", photo_name);
                return 2;
            }
        }

        if (photo_p) {
            fwrite(buffer, 1, BLOCK, photo_p);
        }
    }

    fclose(photo_p);
    fclose(file_p);
    return 0;
}
