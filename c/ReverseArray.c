#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6
/**********************************************************************************************
 * This program creates a function to reverse an array then tests it out in the main
 *
 * @name Cynthia Haque
 * @date 6-30-2024
 * @version 2024 
 ********************************************************************************************** */


/**********************************************************************************************
 * Function 1 :       creates a function called reverseArr() that returns void
 *
 * Purpose:           To reverse the elements of an array
 *
 * Input:             int *arr1, int size
 ************************************************************************************************* */
void reverseArr(int *arr, int size)
{

    int start = 0;
    int end;
    end = size-1;

    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


/**********************************************************************************************
 * Function 2 :       creates a function called printArray() that returns void
 *
 * Purpose:           To print an array
 *
 * Input:             int *arr1, int size
 ************************************************************************************************* */
void printArray(int *arr1, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}


int main()
{
    int array[N];
    int i;

    srand(time(0));

    for(i=0; i<N; i++)
    {
        array[i] = rand()% 100 + 1;
    }

    printf("Original array: \n");
    printArray(array, N);

    printf("\n");

    printf("Reversed elements of an array: \n");
    reverseArr(array, N);
    printArray(array, N);

    return 0;
}
