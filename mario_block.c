#include <stdio.h>
#include <cs50.h>



int main(void)
{

    int n;  //Red point is my brick point. Stop here, temporary
    do
    {
        eprintf("about to prompt user for a number\n");

        n = get_int("Pls, enter a positive Number: ");

    }

    while (n <= 0);

    //Print out this many rows
    for (int i = 0; i < n; i++)

    {

        // Print out this many columns
        for (int j = -1; j < n; j++)

        {

            printf("#");

        }

        printf("\n");

    }

}
