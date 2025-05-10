#include<stdio.h>
#include<stdlib.h>


/**********************************************************************************************
 * This program tests the input from the user that is less than 10 characters
 * 
 * @name Cynthia Haque
 * @date 5-27-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

 int main()
 {
    //declaration
    char list1[10];

    printf("Enter a string that is less than 10 characters \n");
    scanf("%9s", list1);

    printf("You entered: %s\n", list1);

    return 0;
 }