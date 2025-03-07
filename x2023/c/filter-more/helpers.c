#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0; // variable for calculating sum for avg find
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = avg + image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            if (round(avg / 3.0) >= 0)
            {
                // giving avg value to all pixels
                image[i][j].rgbtRed = round(avg / 3.0);
                image[i][j].rgbtGreen = round(avg / 3.0);
                image[i][j].rgbtBlue = round(avg / 3.0);
                avg = 0;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE t[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // making copy of image
            t[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // changing the value to opposite i.e first pixel to last pixel and last to first using copy
            image[i][j] = t[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copyimg[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copyimg[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // we are pixel of image[i][j]
            int red = 0;
            int blue = 0;
            int green = 0;
            int Pixels = 0;
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    // checking the boxes around the pixel by using [-1][-1], [-1][0], [-1][1]

                    if ((h + i >= 0 && h + i < height) &&
                        (w + j >= 0 && w + j < width)) // makes sure we don't go past width/height and 0
                    {
                        Pixels++;
                        red += copyimg[h + i][w + j].rgbtRed;
                        green += copyimg[h + i][w + j].rgbtGreen;
                        blue += copyimg[h + i][w + j].rgbtBlue;
                    }
                }
            }
            // set the current pixel we are on to the avg of the block
            image[i][j].rgbtRed = round(red / (float) Pixels);
            image[i][j].rgbtGreen = round(green / (float) Pixels);
            image[i][j].rgbtBlue = round(blue / (float) Pixels);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // 2d array for gx and gy
    int GX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int GY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    // temporary img for storing the new value of red blue green
    RGBTRIPLE tempimg[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // variables for calculating gx and gy value for red blue and green pixels
            int gyr = 0;
            int gxr = 0;
            int gyb = 0;
            int gxb = 0;
            int gxg = 0;
            int gyg = 0;
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {

                    if (i + h < 0 || i + h > height - 1)
                    {
                        continue;
                    }

                    if (j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }

                    gxr += image[h + i][w + j].rgbtRed * GX[h + 1][w + 1];
                    gxg += image[h + i][w + j].rgbtGreen * GX[h + 1][w + 1];
                    gxb += image[h + i][w + j].rgbtBlue * GX[h + 1][w + 1];

                    gyr += image[h + i][w + j].rgbtRed * GY[h + 1][w + 1];
                    gyg += image[h + i][w + j].rgbtGreen * GY[h + 1][w + 1];
                    gyb += image[h + i][w + j].rgbtBlue * GY[h + 1][w + 1];
                }
            }

            int sred = round(sqrt((gxr * gxr) + (gyr * gyr)));

            int sgreen = round(sqrt((gxg * gxg) + (gyg * gyg)));

            int sblue = round(sqrt((gxb * gxb) + (gyb * gyb)));

            tempimg[i][j].rgbtRed = (sred > 255) ? 255 : sred;
            tempimg[i][j].rgbtGreen = (sgreen > 255) ? 255 : sgreen;
            tempimg[i][j].rgbtBlue = (sblue > 255) ? 255 : sblue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempimg[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempimg[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempimg[i][j].rgbtBlue;
        }
    }
    return;
}
