#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avg = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;
            image[i][j].rgbtRed = (int) round(avg);
            image[i][j].rgbtGreen = (int) round(avg);
            image[i][j].rgbtBlue = (int) round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                          .189 * image[i][j].rgbtBlue;
            double sGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                            .168 * image[i][j].rgbtBlue;
            double sBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                           .131 * image[i][j].rgbtBlue;
            if (sRed > 255)
            {
                sRed = 255;
            }
            if (sGreen > 255)
            {
                sGreen = 255;
            }
            if (sBlue > 255)
            {
                sBlue = 255;
            }

            image[i][j].rgbtRed = (int) round(sRed);
            image[i][j].rgbtGreen = (int) round(sGreen);
            image[i][j].rgbtBlue = (int) round(sBlue);
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
            // changing the value to opposite i.e first pixel to last pixel and last to first using
            // copy
            image[i][j] = t[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
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
                        (w + j >= 0 &&
                         w + j < width)) // makes sure we don't go past width/height and 0
                    {
                        Pixels++;
                        red += copy[h + i][w + j].rgbtRed;
                        green += copy[h + i][w + j].rgbtGreen;
                        blue += copy[h + i][w + j].rgbtBlue;
                    }
                }
            }
            // set the current pixel we are on to the avg of the block
            image[i][j].rgbtRed = round(red / (float) Pixels);
            image[i][j].rgbtGreen = round(green / (float) Pixels);
            image[i][j].rgbtBlue = round(blue / (float) Pixels);
        }
    }
    return;
}
