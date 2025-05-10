#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**********************************************************************************************
 * This program  reads in the Q3.in file containing a list of integers, and determines
 * if that number is perfect, near-perfect or neither
 * 
 * @name Cynthia Haque
 * @date 6-5-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

int sumOfN(int);

int main()
{
    int i;
    int N;


    //read in the file 'Q3.in'
    FILE *myFile = fopen("Q3.in", "r");
   
    while(fscanf(myFile, "%d\n", &N) != EOF)
    {

        int add = sumOfN(N);

        if(N == add)
        {
            printf("perfect\n");
        }
        else if( abs(add - N) <= 2)
        {
            printf("near-perfect\n");
        }
        else
        {
            printf("neither\n");
        }

    }
    //close the file
    fclose(myFile);
    return 0;
}


/*************************************************************************************************
 * Function 1 :       creates a function called sumOfN() that returns an int
 *
 * Purpose:           To calculate the sum of the integers
 *
 * Input:             int x
 * 
 * Output:            sum 
 ************************************************************************************************* */

int sumOfN(int x)
{

    //declare a variable called sum and set it to 0
    int sum = 1;
    int i;

    for(i = 2; i<=sqrt(x); i++)
    {
        if(x % i == 0)
        {
            sum += i;
            if (i != x/i) 
            {
                sum += x/i;
            }
        }

    }

    return sum;
}