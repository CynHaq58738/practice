#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**********************************************************************************************
 * This program randomly generates numbers and bubble sorts them from smallest to largest
 * 
 * @name Cynthia Haque
 * @date 5-21-2024
 * @version 2024 CS2263
 ********************************************************************************************** */
//declare all variables 
int j;
int i;
int k;
double arr[20];
int m;
int r;
int temp;

/*************************************************************************************************
 * Function 2 :       creates a function called printArray() that is void 
 *
 * Purpose:           To print an array showing exactly 4 decimal places for each value in
 *                    a 12 field area, one number per line
 ************************************************************************************************* */
void printArray()
{
    //create a for loop with a printf statement inside
    for( j=0;j<k;j++ )
    {
        printf("\n%12.4f\n\n", arr[j]);
    }
}
 
/*************************************************************************************************
 * Function 3 :       creates a function called bubbleSort() that is void 
 *
 * Purpose:           To sort the double arr[] using the bubbleSort algorithm
 ************************************************************************************************* */
void bubbleSort()
{
    for( m=0;m<k-1;m++ )
    {
        for( r=0;r<k-m-1;r++ )
        {
            if( arr[r]>arr[r+1] )
            {
                temp = arr[r];
                arr[r] = arr[r+1];
                arr[r+1] = temp;
            }
        }
    }
}

/*************************************************************************************************
 * Function 1 :       creates a function called main() that returns an int 
 *
 * Purpose:           To create a randomized array and sort it using bubble sort
 *
 * Input:             empty parameters
 *
 * Output:            return 0
 ************************************************************************************************* */
int main()
{
    //Randomize the numbers each time
    srand( time(0) );

    //randomly generate an int between 10 and 20
    k = rand()%11+10;

    //fill an array with random values between 10 000 and 50 000
    for( i=0;i<k;i++ )
    {
        arr[i] = (double) rand()/RAND_MAX*40.0+10.0;
    }
    //print the array before it is sorted
    printf("Array before it is sorted:\n ");
    printArray();
    
    //call the bubbleSort function
    bubbleSort();

    //print the array after it is sorted
    printf("\nArray after it is sorted:\n ");
    printArray();

    return 0;
}

