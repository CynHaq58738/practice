#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**********************************************************************************************
 * This program creates a header file in order to run the Main.c file
 *
 * @name Cynthia Haque
 * @date 5-23-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//function declarations
void incrementArray(int*, int, int);
void absoluteArray(double*, int);
int* copyAndSortArray(int*, int);
void squareArray(double*, int);
void reverseArray(int*, int);
void printArrayDouble(double*, int);

//define functions
/*************************************************************************************************
 * Function 1 :       creates a function called incrementArray() that returns void
 *
 * Purpose:           To increment the array of integers by the value x
 *
 * Input:             int* array, int length, int x
 ************************************************************************************************* */
void incrementArray(int* array, int length, int x)
{
    int i;
    for( i=0;i<length;i++ )
    {
        array[i] += x; 
    }
}


/*************************************************************************************************
 * Function 2 :       creates a function called absoluteArray() that returns void
 *
 * Purpose:           To take the absolute value of each value in the array of doubles 
 *
 * Input:             double* array, int length
 ************************************************************************************************* */
void absoluteArray(double* array, int length)
{
    int j;
    for( j = 0;j<length;j++ )
    {
        //taking the absolute values of each element
        array[j] = fabs(array[j]);
    }
}


/*************************************************************************************************
 * Function 3 :       creates a function called copyAndSortArray() that returns an int*
 *
 * Purpose:           To take make and sort a copy of an array of integers, 
 *                    sort it then return it
 *
 * Input:             int* array, int length
 * 
 * Output:            copy
 ************************************************************************************************* */
int* copyAndSortArray(int* array, int length)
{
    int k,l;
    //creates a pointer int* called copy and allocates it to the number of bytes to copy
    int* copy = malloc(length* sizeof(int));
    //creates copy
    memcpy(copy, array, length*sizeof(int));
    
    //bubble sort
    for( k=0;k<length-1;k++ )
    {
        for( l=0;l<length-k-1;l++ )
        {
            if( copy[l] > copy[l+1] )
            {
                int temp = copy[l];
                copy[l] = copy[l+1];
                copy[l+1] = temp;
            }
        }
    }
    return copy;
}


/*************************************************************************************************
 * Function 4 :       creates a function called squareArray() that returns void
 *
 * Purpose:           To square each value in the array of doubles
 *
 * Input:             double* array, int length
 ************************************************************************************************* */
void squareArray(double* array, int length)
{
    int m;
    for( m=0;m<length;m++ )
    {
        array[m] *= array[m];
    }
}


/*************************************************************************************************
 * Function 5 :       creates a function called reverseArray() that returns void
 *
 * Purpose:           To reverse the order to an array of integers
 *
 * Input:             int* array, int length
 ************************************************************************************************* */
void reverseArray(int* array, int length)
{
    int r;
    for( r=0;r<length/2;r++ )
    {
        double temp = array[r];
        array[r] = array[length-r-1];
        array[length-r-1] = temp;
    }
}


/*************************************************************************************************
 * Function 6 :       creates a function called printArrayDouble() that returns void
 *
 * Purpose:           To print an array of doubles, one line for each numbers, with 4 decimal
 *                    places in 12 spaces minimum.
 *
 * Input:             double* array, int length
 ************************************************************************************************* */
void printArrayDouble(double* array, int length)
{
    int p;
    for( p=0;p<length;p++ )
    {
        printf("%12.4f\n", array[p]);
    }    
}

#endif//HELPER_H