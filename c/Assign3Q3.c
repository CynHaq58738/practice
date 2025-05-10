#include<stdio.h>
#include<stdlib.h>

/**********************************************************************************************
 * This program prints out the addresses and values for letters of the alphabet
 * with the modification of getting an input from the user and storing it into list2
 * 
 * @name Cynthia Haque
 * @date 5-27-2024
 * @version 2024 CS2263
 ********************************************************************************************** */


int main()
{
    //Declaration and Intialization
    int i;
    //create 3 characters called a, b, c and intialize them to their match: 'a', 'b', 'c'
    char a = 'a', b = 'b', c = 'c';
    //create 3 characters called x, y, z and intialize them to their match: 'x', 'y', 'z'
    char x = 'x', y = 'y', z = 'z';   

    /******************************************************************************
     * create an array of 10 characters in stack memory and call it list1, 
     * then assign them the next 10 letters in the alphabet
     * **************************************************************************** */

    char list1[10] = {'d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};

    /******************************************************************************
     * create an array of 10 characters in heap memory and call it list2, 
     * then assign them the next 10 letters in the alphabet
     * **************************************************************************** */
    //add an extra byte for the null terminator
    char *list2 = (char*) malloc(11 * sizeof(char));

    for( i = 0; i < 11; i++ )
    {
        list2[i] = 'n' + i;
    }

    /******************************************************************************
     * print out the following in order:
     *                                 - variable names
     *                                 - variable address
     *                                 - variable values for both int and char 
     * **************************************************************************** */


    //read in from memory a word from the user and store it into list2
    printf("Enter a word: \n");
    scanf("%10s", list2);

    printf("a: Address = %p, Value (char) = %c, Value (int) = %d \n", &a,  a, a);
    printf("b: Address = %p, Value (char) = %c, Value (int) = %d \n", &b,  b, b);
    printf("c: Address = %p, Value (char) = %c, Value (int) = %d \n", &c, c, c);

    for( i = 0; i < 10; i++ )
    {
        printf("list1[%d]: Address = %p, Value (char) = %c, Value (int) = %d \n", i, &list1[i], list1[i], list1[i]);
    }

    for( i = 0; i < 10; i++ )
    {
        printf("list2[%d]: Address = %p, Value (char) = %c, Value (int) = %d \n", i, &list2[i], list2[i], list2[i]);
    }

    printf("x: Address = %p, Value (char) = %c, Value (int) = %d \n", &x, x, x);
    printf("y: Address = %p, Value (char) = %c, Value (int) = %d \n", &y, y, y);
    printf("z: Address = %p, Value (char) = %c, Value (int) = %d \n", &z, z, z);

    //free the memory
    free(list2);

    return 0;
}


