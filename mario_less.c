/*

Martin Straußberger
one possible solution for pset1: mario_less

*/

#include <stdio.h>
#include <cs50.h>

int main(void)


{
    //Step 1: Figure out how validate input given by user!

    int height;
    do
    {
        printf("enter height: ");
        height = get_int();

    }

    while ( height < 0 || height > 23);

    // Step 2: create pattern on each row (i = row)
    
    for (int i = 0; i < height; i++)

    {
        // Step 3: because of  i and j we print # or _ (l = linespace!)
        
        for (int linespace = 0; linespace <= height; linespace++)

        {

            if ( i + linespace < (height - 1))

                printf(" ");

            else

                printf("#");

        }
            // function for exact 1 Line, -->
            // next Step 4: printf("\n") -> means print New Line
            printf("\n");

    }
}
