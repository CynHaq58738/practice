#include<stdio.h>
#include<stdlib.h>

#define N 10

int* sumOfArr(int*, int*, int);

int main()
{
    int *z;

    int x[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int y[N] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    z =  sumOfArr(x, y, N);

    printf("The result of the array is ==> %d \n", z);

    free(z);

    return 0;

}

int* sumOfArr(int *arr1, int *arr2, int length)
{
    int i;
    int *sum = (int*) malloc(sizeof(int) * N);
    
    for(i=0; i<N; i++)
    {
        sum[i] = arr1[i] + arr2[i]; 
    }

    return sum;

}





