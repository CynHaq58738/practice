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
    char *list2;

    //allocate memory for list2
    list2 = (char*) malloc(11*sizeof(char));

    printf("Enter a string that is less than 10 characters: \n");
    scanf("%10s", list2);

    printf("You entered: %s\n", list2);

    free(list2);

    return 0;
 }