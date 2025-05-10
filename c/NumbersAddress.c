#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**********************************************************************************************
 * This program prints out the random numbers and their addresses 
 * 
 * @name Cynthia Haque
 * @date 5-28-2024
 * @version 2024 
 ********************************************************************************************** */

int main()
{
    int i;
    int *numbers;
    int length;

    //randomize the numbers
    srand(time(0));

    //read in the length of the array
    printf("Enter a number for the length of the array: ");
    scanf("%d", &length);

    //allocate memory for the array
    numbers = (int*) malloc((length+1)*sizeof(int));

    for(i=0; i<length+1; i++)
    {
        numbers[i] = rand()%500;
        printf("numbers[%d] = %d, Address = %5d \n", i, numbers[i], (int)((long)&numbers[i] % 100000));
    }

    free(numbers);

    return 0;
}