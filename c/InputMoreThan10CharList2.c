#include<stdio.h>
#include<stdlib.h>

/**********************************************************************************************
 * This program tests the input from the user that is more than 10 characters
 * 
 * @name Cynthia Haque
 * @date 5-27-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

 int main()
 {
    //declaration
    char *list2;
    int length;

    //allocate the memory for the string
    printf("Enter the length of the string: \n");
    scanf("%d", &length);

    list2 = (char*) malloc((length+1) * sizeof(char) );

    if(list2 == NULL)
    {
        printf("Error: Could not allocate the memory\n");
        return 1;
    }

    //ask the user for a string
    printf("Enter a string: \n");
    //consume newline character from the previous scanf
    getchar();
    fgets(list2, length+1, stdin);

    printf("You entered: %s \n", list2);

    free(list2);

    return 0;
 }