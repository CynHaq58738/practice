#include <stdio.h>
#include <string.h>
#include "Person.h"

/**********************************************************************************************
 * This program creates a person
 *
 * @name Cynthia Haque
 * @date 7-4-2024
 * @version 2024 
 ********************************************************************************************** */
int main()
{
    person myPerson;

    myPerson.day = 23;
    myPerson.year = 2005;
    myPerson.month = 10;
    myPerson.name = strdup("Cynthia Haque");

    person OtherPerson;

    OtherPerson.day = 24;
    OtherPerson.year = 1997;
    OtherPerson.month = 3;
    OtherPerson.name = strdup("Mina Myoui");

    printPerson(&myPerson);
    printf("\n");
    printPerson(&OtherPerson);

    freePerson(&myPerson);
    freePerson(&OtherPerson);

    return 0;
}