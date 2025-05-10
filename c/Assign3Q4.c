#include <stdio.h>
#include <stdlib.h>

void increment(int, double*, int);

int main()
{
    int a=10;
    int n = 15;
    double* x;
    int i;

    printf("Truncated address of a: %05d\n", (int)((long)&a % 100000));
    printf("Truncated address of n: %05d\n", (int)((long)&n % 100000));
    printf("Truncated address of x: %05d\n", (int)((long)&x % 100000));
    printf("Truncated address of i: %05d\n", (int)((long)&i % 100000));

    x = (double*) malloc(15 * sizeof(double) );


    for(i=0; i<a; i++)
    {
        x[i] = i*i;
        printf("x[%d] = %4f \n", i, x[i]);
    }
    puts("");
    puts("");

    increment(a,x,n);

    for(i=0; i<a; i++)
        printf("x[%d] = %4f \n", i, x[i]);

       system("PAUSE");
       return 0;

}

void increment(int val, double* array, int size)
{
    int i;
    
    printf("Truncated address of val: %05d\n", (int)((long)&val % 100000));
    printf("Truncated address of array: %05d\n", (int)((long)&array % 100000));
    printf("Truncated address of size: %05d\n", (int)((long)&size % 100000));
    printf("Truncated address of i: %05d\n", (int)((long)&i % 100000));

    for(i=0; i<size; i++)
        array[i] = array[i] + val;
}
