#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int max(int x, int y);
int min(int x, int y);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //for each pixel, take average of R, G, B values
    //then make sure each pixel have same value (the avg) for each R, G, B
    //correct rounding error
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //formula in specs
    //values of each R, B, and G cannot exceed 255
    //round each value to integers: round()

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));

            //Set values >255 back to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //change values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //store whole image somewhere, then loop through image from right to left

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Allocate space for my variable
            int *blue = malloc(sizeof(int));
            int *green = malloc(sizeof(int));
            int *red = malloc(sizeof(int));

            //move left half to x, right half to left, and x to right for each of three integers within RGBTRIPLE
            *blue = image[i][j].rgbtBlue;
            *green = image[i][j].rgbtGreen;
            *red = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;

            image[i][width - 1 - j].rgbtBlue = *blue;
            image[i][width - 1 - j].rgbtGreen = *green;
            image[i][width - 1 - j].rgbtRed = *red;

            //free up allocated space
            free(blue);
            free(green);
            free(red);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyimage[height][width];
    // Must store whole image in a new image and work through the new images, make changes in the old images
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Store values in new integers blue, green & red
            int avgblue = 0; //outside for loop for declarations
            int avggreen = 0;
            int avgred = 0;
            int pixelcount = 0;

            for (int x = max(i - 1, 0); x <= min(height - 1, i + 1); x++)
            {
                for (int y = max(j - 1, 0); y <= min(width - 1, j + 1); y++)
                {

                    // Counters for my averages
                    avgblue += image[x][y].rgbtBlue;
                    avggreen += image[x][y].rgbtGreen;
                    avgred += image[x][y].rgbtRed;
                    pixelcount++;
                }
            }
            // Average out by pixels in sourrounding
            copyimage[i][j].rgbtBlue = round((float)avgblue / pixelcount);
            copyimage[i][j].rgbtGreen = round((float)avggreen / pixelcount);
            copyimage[i][j].rgbtRed = round((float)avgred / pixelcount);
        }
    }
    //outside all for loops, use double for loops to assign everything in image[i][j] to copyimage[i][j]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copyimage[i][j];
        }
    }
    return;

}

// I recieved help with this function from TA Natalie at office hours on Thursday night
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}


int min(int x, int y)
{
    if (y > x)
    {
        return x;
    }
    return y;
}
