#include <stdio.h>
#include <stdlib.h>
#define N 32
/**********************************************************************************************
 * This program performs several binary conversions
 * 
 * @name Cynthia Haque
 * @date 1-25-2025
 * @version 2025 CS2253
 ********************************************************************************************** */
//prototype
int* decToBin(int);
void printArr(int*);


int main()
{
    int dec;
    int* bin = decToBin(dec);
    printf("Enter a decimal number: \n");
    scanf("%d", &dec);
    printf("The binary representation is:\n");
    printArr(bin);

    free(bin);

    return 0;
}

//Method 1: Convert a decimal number to binary array
//Input: int decimal
//Output: int binary
int* decToBin(int decimal)
{
    int* bin = (int*) malloc(N*sizeof(int));
    int i;
    for(i=0; i<N; i++)
    {
        bin[i] = decimal % 2;
        //decimal/=10;
    }
    return bin;
}

//Method 2: print an array
//Input: int arr[]              
//Output: void
void printArr(int *arr)
{
    int i;
    for(i=N-1; i>=0; i--)
    {
        //print in nibbles (4 spaces)
        printf("%d", arr[i]);
        if(i%4 == 0 && i !=0)
        {
            printf(" ");
        }
    }
    printf("\n");
}