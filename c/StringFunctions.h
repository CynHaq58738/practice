#ifndef SRTRINGFUCNTIONS_H
#define SRTRINGFUCNTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void strlength();
void stringCopy();
void stringCat();
void stringComparison();


/*************************************************************************************************
 * Function 1 :       creates a function called strlengthOfArray that returns void
 *
 * Purpose:           To print the length of a string
 *
 * Input:             none
 ************************************************************************************************* */

void strlength()
{
    char language[] = "C Programming";
    printf("%s", language);

    //%zu format specifier for strlen()
    printf("\nLength: %zu", strlen(language));

}

/*************************************************************************************************
 * Function 2 :       creates a function called stringCopy that returns void
 *
 * Purpose:           To print the copy of a string
 *
 * Input:             none
 ************************************************************************************************* */
void stringCopy()
{
    char food[] = "Pizza";

    //same length of the food copied into the bestFood
    char bestFood[strlen(food)];
    //strcpy takes two parameters : destination = bestFood and source = food
    strcpy(bestFood, food);

    printf("%s\n", bestFood);

}

/*************************************************************************************************
 * Function 3 :       creates a function called stringCat that returns void
 *
 * Purpose:           To print the concatination of string
 *
 * Input:             none
 ************************************************************************************************* */
void stringCat()
{
    char text1[] = "Hey, ";
    char text2[] = "How are you?";

    strcat(text1, text2);

    printf("%s\n", text1);

}

/******************************************************************************************************
 * Function 4 :       creates a function called stringComparison that returns void
 *
 * Purpose:           To compare two strings returns non-zero value if not equal and 0 if equal
 *
 * Input:             none
 ****************************************************************************************************** */
void stringComparison()
{
    char text1[] = "abcd";
    char text2[] = "efgh";
    int result;

    result = strcmp(text1, text2);

    printf("%d", result);

}

/******************************************************************************************************
 * Function 5 :       creates a function called stringnCopy that returns void
 *
 * Purpose:           To copy a specific amount of strings to another
 *
 * Input:             none
 ****************************************************************************************************** */
void stringnCopy()
{
    char text1[] = "Wassup";
    char text2[] = "Bro";

    strncpy(text2,text1, 2);

    printf("%s\n", text2); 

}






















#endif