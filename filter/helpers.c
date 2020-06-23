#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // printf("%i\n", image[i][j].rgbtBlue);
            int colour_avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            // printf("%i\n", colour_avg);
            image[i][j].rgbtRed = colour_avg;
            image[i][j].rgbtGreen = colour_avg;
            image[i][j].rgbtBlue = colour_avg;
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
            int new_Red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int new_Green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int new_Blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (new_Red > 255)
            {
                new_Red = 255;
            }
            if (new_Green > 255)
            {
                new_Green = 255;
            }
            if (new_Blue > 255)
            {
                new_Blue = 255;
            }


            printf("%i, %i, %i\n", new_Red, new_Blue, new_Green);
            image[i][j].rgbtRed = new_Red;
            image[i][j].rgbtGreen = new_Green;
            image[i][j].rgbtBlue = new_Blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE arr[width];
        for (int j = 0; j < width; j++)
        {
            arr[j] = image[i][j];
        }

        for (int g = width - 1; g > -1; g -= 1)
        {
            image[i][g] = arr[width - g];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    int red;
    int green;
    int blue;
    float num_pixels;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = 0;
            green = 0;
            blue = 0;
            num_pixels = 0.00;

            for (int h = -1; h < 2; h++)
            {
                if (i + h < 0 || i + h >= height)
                {
                    continue;
                }

                for (int w = -1; w < 2; w++)
                {
                    if (j + w < 0 || j + w >= width)
                    {
                        continue;
                    }
                    red += image[i + h][j + w].rgbtRed;
                    green += image[i + h][j + w].rgbtGreen;
                    blue += image[i + h][j + w].rgbtBlue;
                    num_pixels++;
                }
            }

            int red_avg = round(red / num_pixels);
            int green_avg = round(green / num_pixels);
            int blue_avg = round(blue / num_pixels);

            temp_image[i][j].rgbtRed = red_avg;
            temp_image[i][j].rgbtGreen = green_avg;
            temp_image[i][j].rgbtBlue = blue_avg;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp_image[i][j].rgbtBlue;
        }
    }
    return;
}
