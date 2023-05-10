#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "DefineFilters.h"

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{

    // Define allowable filters
    const char *filters = "bgrs";

    // Get filter flag and check validity
    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        fprintf(stderr, "Invalid filter.\n");
        return 1;
    }

    // Ensure only one filter
    if (getopt(argc, argv, filters) != -1)
    {
        fprintf(stderr, "Only one filter allowed.\n");
        return 2;
    }

    //    fprintf(stderr, "%d %s %s %s %s\n",argc,argv[0],argv[1],argv[2],argv[3]);

    // Ensure proper usage
    //    if (argc != optind + 2)
    if (argc != 4)
    {
        fprintf(stderr, "Usage: filter [flag] infile outfile\n");
        return 3;
    }

    // Remember filenames
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Open input file
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 4;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "wb");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
    bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 6;
    }

    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    // Allocate memory for image
    //    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    RGBTRIPLE(*image)[width] = (RGBTRIPLE(*)[width])malloc(height * width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        fprintf(stderr, "Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    // Determine padding for scanlines
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
        // Read row into pixel array
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        // Skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    vector<vector<RGBTRIPLE>> image1{height};
    for (int i=0;i<height;i++)
        for (int j=0;j<width;j++)
            image1[i].push_back(image[i][j]);

        //                cout << height <<" " <<image1.size()<<endl;
        //                cout << width<<" "<<image1[0].size()<<endl;


        // Filter image
        switch (filter)
        {
            // Blur
            case 'b':
                blur(image1);
                break;

                // Grayscale
                case 'g':
                    grayscale(image1);
                    break;

                    // Reflection
                    case 'r':
                        reflect(image1);
                        break;

                        // Sepia
                        case 's':
                            sepia(image1);
                            break;
        }
        for (int i=0;i<height;i++)
            for (int j=0;j<width;j++)
                image[i][j]=image1[i][j];


            // Write outfile's BITMAPFILEHEADER
            fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

            // Write outfile's BITMAPINFOHEADER
            fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

            // Write new pixels to outfile
            for (int i = 0; i < height; i++)
            {
                // Write row to outfile
                fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

                // Write padding at end of row
                for (int k = 0; k < padding; k++)
                {
                    fputc(0x00, outptr);
                }
            }

            // Free memory for image
            free(image);

            // Close infile
            fclose(inptr);

            // Close outfile
            fclose(outptr);

            return 0;
}