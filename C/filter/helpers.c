#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculating average of RGB for a pixel
            int a = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = a;
            image[i][j].rgbtGreen = a;
            image[i][j].rgbtRed = a;
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
            int a, b, c;
            a = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            b = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            c = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            // if statements have been used to prevent integer overflow
            if (a > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = a;
            }
            if (b > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = b;
            }
            if (c > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = c;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    // replacing pixels on RHS to LHS and vice versa
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // declaring and initialising temporarary variables to 0 to store pixels' new data
    unsigned long long int sum1[height][width], sum2[height][width], sum3[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum1[i][j] = 0;
            sum2[i][j] = 0;
            sum3[i][j] = 0;
        }
    }

    // for those pixels which are surrounded by 8 pixels
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    {
                        sum1[i][j] += image[k][l].rgbtRed;
                        sum2[i][j] += image[k][l].rgbtGreen;
                        sum3[i][j] += image[k][l].rgbtBlue;
                    }
                }
            }
            sum1[i][j] = round(sum1[i][j] / 9.0);
            sum2[i][j] = round(sum2[i][j] / 9.0);
            sum3[i][j] = round(sum3[i][j] / 9.0);
        }
    }

    // for pixels on corners

    // don't attempt to understand following module.you can't. It's a mess which took hell a lot of time to write
    int array1[4][4] = {{0, 1, 1, 0}, {0, 1, 1, 0}, {height - 1, height - 2, height - 2, height - 1}, {height - 1, height - 2, height - 2, height - 1}};
    int array2[4][4] = {{1, 0, 1, 0}, {width - 2, width - 1, width - 2, width - 1}, {width - 2, width - 1, width - 2, width - 1}, {1, 0, 1, 0}};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum1[array1[i][0]][array2[i][1]] += image[array1[i][j]][array2[i][j]].rgbtRed;
            sum2[array1[i][0]][array2[i][1]] += image[array1[i][j]][array2[i][j]].rgbtGreen;
            sum3[array1[i][0]][array2[i][1]] += image[array1[i][j]][array2[i][j]].rgbtBlue;
        }
        sum1[array1[i][0]][array2[i][1]] = round((sum1[array1[i][0]][array2[i][1]]) / 4.0);
        sum2[array1[i][0]][array2[i][1]] = round((sum2[array1[i][0]][array2[i][1]]) / 4.0);
        sum3[array1[i][0]][array2[i][1]] = round((sum3[array1[i][0]][array2[i][1]]) / 4.0);
    }
    // for pixels on the edges

    //(for edges on vertical sides)
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum1[i][0] += image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed;
            sum2[i][0] += image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen;
            sum3[i][0] += image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue;
        }
        sum1[i][0] = round((sum1[i][0]) / 6.0);
        sum2[i][0] = round((sum2[i][0]) / 6.0);
        sum3[i][0] = round((sum3[i][0]) / 6.0);
        for (int j = width - 2; j < width; j++)
        {
            sum1[i][height - 1] += image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed;
            sum2[i][height - 1] += image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen;
            sum3[i][height - 1] += image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue;
        }
        sum1[i][height - 1] = round(sum1[i][height - 1] / 6.0);
        sum2[i][height - 1] = round(sum2[i][height - 1] / 6.0);
        sum3[i][height - 1] = round(sum3[i][height - 1] / 6.0);
    }

    //(for edges on horizontal sides)
    for (int j = 1; j < width - 1; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            sum1[0][j] += image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed;
            sum2[0][j] += image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;
            sum3[0][j] += image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;
        }
        sum1[0][j] = round(sum1[0][j] / 6.0);
        sum2[0][j] = round(sum2[0][j] / 6.0);
        sum3[0][j] = round(sum3[0][j] / 6.0);
        for (int i = height - 2; i < height; i++)
        {
            sum1[height - 1][j] += image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed;
            sum2[height - 1][j] += image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;
            sum3[height - 1][j] += image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;
        }
        sum1[height - 1][j] = round(sum1[height - 1][j] / 6.0);
        sum2[height - 1][j] = round(sum2[height - 1][j] / 6.0);
        sum3[height - 1][j] = round(sum3[height - 1][j] / 6.0);
    }

    // copying pixels' new data from temporary variables to images[i][j]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = sum1[i][j];
            image[i][j].rgbtGreen = sum2[i][j];
            image[i][j].rgbtBlue = sum3[i][j];
        }
    }
    return;
}
