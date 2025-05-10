#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************************
 * This program calculates the average gpa based on the percentages specified by the user
 *
 * @name Cynthia Haque
 * @date 1-1-2025
 * @version 2025
 ********************************************************************************************** */

double getGpaVal(int);

int main()
{

    int percent, length;
    printf("Enter the number of percentages: ");
    scanf("%d", &length);

    int* listOfPercents = (int*) malloc(length*sizeof(int));
    double totalGpaAvg = 0;
    
    
    int i;
    for(i=0; i<length; i++)
    {
        printf("Enter a percentage: ");
        scanf("%d", &percent);
        listOfPercents[i] = percent;
        totalGpaAvg += getGpaVal(percent); 
    }
    double gpa = totalGpaAvg/length;

    printf("The average gpa is %.2f ", gpa);

    free(listOfPercents);

    return 0;
}

double getGpaVal(int percent)
{
    double gpa;
    if(percent>=90)
    {
        return gpa = 4.3;
    }
    else if(percent>=85 && percent<=89)
    {
        return gpa = 4.0;
    }
    else if(percent>=80 && percent<=84)
    {
        return gpa = 3.7;
    }
    else if(percent>=75 && percent<=79)
    {
        return gpa = 3.3;
    }
    else if(percent>=70 && percent<=74)
    {
        return gpa = 3.0;
    }
    else if(percent>=65 && percent<=69)
    {
        return gpa = 2.7;
    }
    else if(percent>=58 && percent<=64)
    {
        return gpa = 2.3;
    }
    else if(percent>=50 && percent<=57)
    {
        return gpa = 2.0;
    }
    else if(percent>=45 && percent<=49)
    {
        return gpa = 1.7;
    }
    else
    {
        return gpa = 0.0;
    }
}


