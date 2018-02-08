/*

Martin Straußberger
pset1: greedy/cash.c

*/

#include<stdio.h>
#include<cs50.h>
#include <math.h>

//declerate variable for change in cents
int change(int cents);

int main(void)


{
    //loop construct -> do while loop
    float given_amount;
    do

    {
        //Given amount, by user print by change owed

        given_amount = get_float("Change I owe: ");

        // Zero Reminder for User. Printf, if value is 0 || < 0 !
        if(given_amount == 0||given_amount <= 0)
        printf("Pls enter a Value greater than Zero: \n");

    }

    // <= 0 --> it not possible to enter 0 or less, if so it asks you again to enter a value like in line 23
    while ( given_amount <= 0);


        // Output of rounded change by given_amount
        printf("%d coins", change(round(given_amount * 100)));

    }

    int change(int cents)

    {

         printf("Used: ");

         //one line return for all variables (values) given by cs50 called:
         // quarter = 25
         // dime = 10
         // nickel = 5
         // rest = 1
         // cents
         return cents /25 + (cents %25) /10 + ((cents %25) %10) /5 + ((cents %25) %10) %5;

}


