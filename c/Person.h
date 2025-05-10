#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************************************
 * This program defines a person
 *
 * @name Cynthia Haque
 * @date 7-3-2024
 * @version 2024 
 ********************************************************************************************** */

//define a person structure
typedef struct Person
{
    int year;
    int month;
    int day;
    char *name;
}person;

/*************************************************************************************************
 * Function 1 :       creates a function called makePerson() that returns person*
 *
 * Purpose:           To create a person
 *
 * Input:             int y, int m, int d, char *n
 * 
 * Output:            person *newPerson 
 ************************************************************************************************* */
person* makePerson(int y, int m, int d, char *n)
{
    person *newPerson = (person*) malloc(sizeof(person));
    newPerson->year = y;
    newPerson->month = m;
    newPerson->day = d;
    newPerson->name = strdup(n);

    return newPerson;
}

/*************************************************************************************************
 * Function 2 :       creates a function called freePerson() that returns void
 *
 * Purpose:           To give memory back to computer from person
 *
 * Input:             person *myPerson
 ************************************************************************************************* */
void freePerson(person *myPerson)
{
    free(myPerson->name);
    freePerson(myPerson);
}

/*************************************************************************************************
 * Function 3 :       creates a function called peintPerson() that returns void
 *
 * Purpose:           To print out the person
 *
 * Input:             person *myPerson
 ************************************************************************************************* */
void printPerson(person *myPerson)
{
    if(myPerson->name == NULL)
    {
        printf("My person is empty.\n");
    }

    printf("Date of birth: %d/%d/%d\n", myPerson->year, myPerson->month, myPerson->day);
    printf("Name: %s\n", myPerson->name);

}

#endif