#include<stdio.h>
#include<string.h>

/**********************************************************************************************
 * This program uses the datatype structure box to take the area of a triangle based 
 * on the values created in the box
 * 
 * @name Cynthia Haque
 * @date 5-31-2024
 * @version 2024 CS2263
 ********************************************************************************************** */
typedef struct 
{
    double base;
    double height;

} values;

double getAreaOfTriangle(values *thisvalues)
{
    double result;
    result = (thisvalues->base * thisvalues->height)/2;

    return result;
}

int main()
{
    values myValues = {1.54, 3.32};
    printf("base: %.2f, Address: %p \n", myValues.base, &myValues.base);
    printf("height: %.2f, Address: %p \n", myValues.height, &myValues.height);

    double answer = getAreaOfTriangle(&myValues);
    printf("The area of the triangle is: %.2f \n ", answer);


    values yourValues = {2.45, 6.99};
    printf("base: %.2f, Address: %p \n", yourValues.base, &yourValues.base);
    printf("height: %.2f, Address: %p \n", yourValues.height, &yourValues.height);
    double answer2 = getAreaOfTriangle(&yourValues);
    printf("The area of the triangle is: %.2f \n ", answer2);


    values *thatvalues = &myValues;
    printf("base: %.2f, Address: %p \n", thatvalues->base, &thatvalues->base);
    printf("height: %.2f, Address: %p \n", thatvalues->height, &thatvalues->height);

    return 0;
}