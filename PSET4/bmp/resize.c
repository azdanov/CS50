/**
 * Resizes a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    int resize_fact = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL) {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL) {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0) {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    /**
     *  TODO:  biSizeImage
     */

    int infile_width = bi.biWidth, infile_height = bi.biHeight;

    bi.biWidth = bi.biWidth * resize_fact;
    bi.biHeight = bi.biHeight * resize_fact;

    // determine padding for scanlines (in bytes)
    int infile_padding = (4 - (infile_width * sizeof(RGBTRIPLE)) % 4) % 4;
    int outfile_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + outfile_padding) * abs(bi.biHeight);
    bf.bfSize = bf.bfOffBits + bi.biSizeImage;

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(infile_height); i < biHeight; i++) {
        // iterate over pixels in scanline
        RGBTRIPLE scanline[infile_width];
        for (int l = 0; l < infile_width; ++l) {
            fread(&scanline[l], sizeof(RGBTRIPLE), 1, inptr);
        }

        fseek(inptr, infile_padding, SEEK_CUR);
        
        for (int y = 0; y < resize_fact; ++y) {
            for (int pixel = 0, size = sizeof(scanline) / sizeof(scanline[0]); pixel < size; ++pixel) {
                for (int x = 0; x < resize_fact; ++x) {
                    fwrite(&scanline[pixel], sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            for (int k = 0; k < outfile_padding; k++) {
                fputc(0x00, outptr);
            }
        }

    }

    fclose(inptr);

    fclose(outptr);

    return 0;
}
