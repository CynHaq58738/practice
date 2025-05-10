#include <time.h>
#include "Helper.h"

/**********************************************************************************************
 * This program tests the function are defined in the 'Helper.h' 
 *
 * @name Cynthia Haque
 * @date 5-23-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define the size of the array
#define N 10

//declare for loop indexes
int c,d;

/*************************************************************************************************
 * Function 2 :       creates a function called printArray() that returns void
 *
 * Purpose:           To print an array of integers
 *
 * Input:             int* array, int length
 ************************************************************************************************* */

void printIntArray(int* array, int length)
{
    int y;
    for( y=0;y<length;y++ )
    {
        printf("%d\n", array[y]);
    }    
}

/*************************************************************************************************
 * Function 1:         creates a function called main() that returns an int 
 *
 * Purpose:            To test the function are defined in the 'Helper.h' 
 *
 * Input:              empty parameters
 *
 * Output:             return 0
 ************************************************************************************************* */
int main()
{
    //randomize the numbers
    srand(time(0));

    //declare an int array to be of size N
    int array[N];

    //randomly generate integers between 0 and 100 and assign it to the array of integers
    for( c=0;c<N;c++ )
    {
        array[c] = rand()%100;
    }

    printf("Initial array of Integers:\n");
    printIntArray(array, N);

    //increment each element in the array by a provided value x
    incrementArray(array, N, 9);

    printf("Array after incrementing by 9:\n");
    printIntArray(array, N);

    //create and sort a copy of the array and return it by assigning it to an int* called sortedArray
    int* sortedArray = copyAndSortArray(array, N);

    printf("Sorted array of the integers:\n");
    printIntArray(sortedArray, N);

    //reverse the order of the array of integers
    reverseArray(sortedArray, N);

    //print the reverse array of integers
    printf("Reversed order of the array of integers:\n");
    printIntArray(sortedArray, N);
    
    //free the memory when not in use
    free(sortedArray);

    //convert integer array to double array in order for the functions to work

    //declare a double array to be of size N and call it arrayDouble
    double arrayDouble[N];

    for( d=0;d<N;d++ )
    {
        arrayDouble[d] = (double) array[d];
    }

    //take the absolute value for each element in the array of doubles
    absoluteArray(arrayDouble, N);

    printf("Absolute value for the array of doubles:\n");
    printArrayDouble(arrayDouble, N);

    //square each value in the array of doubles
    squareArray(arrayDouble, N);

    printf("Squared array of doubles:\n");
    printArrayDouble(arrayDouble, N);

    //print the final output of the array of doubles
    printf("Final output for the array of doubles:\n");
    printArrayDouble(arrayDouble, N);
   
    return 0;
}
 