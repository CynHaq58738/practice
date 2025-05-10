#include <stdio.h>
#include <stdlib.h>


/**********************************************************************************************
 * This program creates a program to find the volume of something
 *
 * @name Cynthia Haque
 * @date 7-2-2024
 * @version 2024 
 ********************************************************************************************** */

int main()
{

    int length, width, height, volume;

    char choice;

    do
    {
        printf("Enter a number for the length: \n");
        scanf("%d", &length);

        printf("Enter a number for the width: \n");
        scanf("%d", &width);

        printf("Enter a number for the height: \n");
        scanf("%d", &height);

        scanf("%*c");

        printf("Would you like to continue (y/n): \n");
        scanf("%c", &choice);


    } while (choice == 'y' || choice == 'Y');
    

    volume = length * width * height;

    printf("The volume is : %d \n", volume);

    return 0;
}
