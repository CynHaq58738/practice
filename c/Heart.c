#include <stdio.h>
#include <stdlib.h>


/****************************************************************************************************
 * This program draws as many hearts the user wants.
 * 
 * @name Cynthia Haque
 * @date 9-2-2024
 * @version 2024 
 *************************************************************************************************** */
int main()
{
    char response = ' ';
    int num;
    int i;

    do
    {
        printf("Do you want to draw a heart? (y/n):\n");
        //extra space to clear the newline character
        scanf(" %c", &response);

        if(response == 'y')
        {
            printf("Enter a number for the amount of hearts to be drawn:\n ");
            scanf("%d", &num);
        
            for(i = 0; i<num; i++)
            {
                printf("  ***   ***    \n");
                printf(" ***** *****   \n");
                printf(" ***********   \n");
                printf("  *********    \n");
                printf("   *******     \n");
                printf("    *****      \n");
                printf("     ***       \n");
                printf("      *        \n");
                printf("\n");
            }
        }    

    } while (response == 'y');
    
    return 0;
}
