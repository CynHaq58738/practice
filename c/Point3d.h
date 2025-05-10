#ifndef POINT3D_H
#define POINT3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/**********************************************************************************************
 * This program creates a header file in order to run the Driver.c file
 *
 * @name Cynthia Haque
 * @date 6-10-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define structure
typedef struct Point3D
{
    double x;
    double y;
    double z;
}point3D;

//define the prototypes
point3D* makePoint3D(double, double, double);
void printPoint3D(point3D*);
point3D* midpoint(point3D*, point3D*);
double distance(point3D*, point3D*);
point3D* scalarMult(double, point3D*);

//define the functions
/*************************************************************************************************
 * Function 1 :       creates a function called makePoint3D() that returns point3D*
 *
 * Purpose:           To allocate memory for point3D then return its address
 *
 * Input:             double x, double y, double z
 * 
 * return:            point3D address
 ************************************************************************************************* */
point3D* makePoint3D(double x, double y, double z)
{
    point3D *address = (point3D*) malloc(sizeof(point3D));

    address->x = x;
    address->y = y;
    address->z = z;

    return address;
}

/*************************************************************************************************
 * Function 2 :       creates a function called printPoint3D() that returns void
 *
 * Purpose:           To print a point in standard output (format 3 decimal places)
 *
 * Input:             point3D *p
 ************************************************************************************************* */
void printPoint3D(point3D *p)
{
    printf("(%.3f, %.3f, %.3f)\n", p->x, p->y, p->z);

}

/*************************************************************************************************
 * Function 3 :       creates a function called midpoint() that returns point3D*
 *
 * Purpose:           To calculate the midpoint between two of the provided point3Ds
 *
 * Input:             point3D* p1, point3D* p2
 * 
 * return:            point3D p3
 ************************************************************************************************* */
point3D* midpoint(point3D *p1, point3D *p2)
{
    point3D *p3;

    p3 = makePoint3D((p1->x + p2->x)/2, (p1->y + p2->y)/2, (p1->z + p2->z)/2);

    return p3;

}

/*************************************************************************************************
 * Function 4 :       creates a function called distance() that returns double
 *
 * Purpose:           To calculate the distance between two of the provided point3Ds
 *
 * Input:             point3D *p1, point3D *p2 
 * 
 * return:            double calcDist
 ************************************************************************************************* */
double distance(point3D *p1, point3D *p2)
{
    double calcDist;

    calcDist = sqrt(pow(p2->x - p1->x,2) + pow(p2->y - p1->y,2) + pow(p2->z - p1->z,2));

    return calcDist;

}

/*************************************************************************************************
 * Function 5 :       creates a function called add() that returns point3D*
 *
 * Purpose:           To add two point3Ds and then return the new point3D
 *
 * Input:             point3D *p1, point3D *p2 
 * 
 * return:            point3D p3
 ************************************************************************************************* */
point3D* add(point3D *p1, point3D *p2)
{
    point3D *p3;
    
    p3 = makePoint3D(p1->x + p2->x, p1->y + p2->y, p1->z + p2->z); 

    return p3;

}

/*************************************************************************************************
 * Function 6 :       creates a function called scalarMult() that returns point3D*
 *
 * Purpose:           To multiply a double value by a point3D value
 *                    then return the new point3D
 *
 * Input:             double scalar, point3D *p1 
 * 
 * return:            point3D p2
 ************************************************************************************************* */
point3D* scalarMult(double scalar, point3D *p1)
{
    point3D *p2;

    p2 = makePoint3D(scalar * p1->x, scalar * p1->y, scalar * p1->z); 

    return p2;
}

#endif