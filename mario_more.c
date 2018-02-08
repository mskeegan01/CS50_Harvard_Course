/*

Martin Straußberger
one possible solution for pset1: mario_comfortable


*/

#include <stdio.h>
#include <cs50.h>

int main(void)


{
    //Step 1: Figure out how validate input given by user!

    int height;
    do
    {

        height = get_int("Enter the height of your Pyramid: ");

    }

    while ( height < 0 || height > 23);

    // Step 2: create pattern
    
    for (int i = 0; i < height; i++)  // i = row

    {

        for (int linespace = 0; linespace <= 2 * height + 2; linespace++) // linespace

        {

            if (i + linespace < (height -1) || linespace == height || linespace == height + 1) // linespace == height +1 --> abstand zw. HalbPyramiden

                printf(" ");

            else if (i + linespace >= height -1 && linespace - i <= height + 2)

                printf("#");


        }

            // function for exact 1 Line, -->
            // next Step 4: printf("\n") -> means print New Line
            
            printf("\n");

    }
}
