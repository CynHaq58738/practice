#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include "Node.h"


/**********************************************************************************************
 * This program creates a header file for the LinkedList in order to create a LinkedList
 *
 * @name Cynthia Haque
 * @date 6-15-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define LinkedList
typedef struct LinkedList
{
    node *head;
}LL;


//function declarations
LL* makeLL();
void insertFront(LL*, int);
void printLL(LL*, int);
void freeLL(LL*);
void freeNode(node*);
void deleteFront(LL*);
int search(LL*, int);


//define functions
/*************************************************************************************************
 * Function 1 :       creates a function called makeLL() that returns LL*
 *
 * Purpose:           To create a LinkedList
 *
 * Input:             none
 * 
 * Output:            LL* current
 ************************************************************************************************* */
LL* makeLL()
{
    LL* current = (LL*) malloc(sizeof(LL));
    current->head = NULL;

    return current;
}


/*************************************************************************************************
 * Function 2 :       creates a function called insertFront() that returns void
 *
 * Purpose:           To insert a node at the front of the LinkedList
 * 
 * Input:             LL* myList, int data
 ************************************************************************************************* */
void insertFront(LL* myList, int data)
{
    node* newNode = makeNode(data);
    newNode->next = myList->head;
    myList->head = newNode;
    
}


/*************************************************************************************************
 * Function 3 :       creates a function called printLL() that returns void
 *
 * Purpose:           To print the LinkedList
 * 
 * Input:             LL* myList, int data
 ************************************************************************************************* */
void printLL(LL* myList, int data)
{
    if(myList->head == NULL)
    {
        printf("The LinkedList is empty. \n");
    }
    else
    {
        node* current = myList->head;
        int i = 0;
        do
        {
            printf("printing node %d \n", i);
            printNode(current);
            current = current->next;
            i++; 
        } while (current !=NULL);
    }
}


/*************************************************************************************************
 * Function 4 :       creates a function called freeLL() that returns void
 *
 * Purpose:           To give back the space used for the LinkedList
 * 
 * Input:             LL* myList
 ************************************************************************************************* */
void freeLL(LL* myList)
{
    node* current = myList->head;

    while (current!=NULL)
    {
        node* thisOne = current;
        current = current->next;
        freeNode(thisOne);
    }
    myList->head = NULL;
    free(myList);
    
}


/*************************************************************************************************
 * Function 5 :       creates a function called freeNode() that returns void
 *
 * Purpose:           To give back the space used for the node
 * 
 * Input:             node*
 ************************************************************************************************* */
void freeNode(node* current)
{
    current->x = rand();
    current->next = NULL;
    free(current);
}


/*************************************************************************************************
 * Function 6 :       creates a function called deleteFront() that returns void
 *
 * Purpose:           To delete the first node in the LinkedList
 * 
 * Input:             LL* myList
 ************************************************************************************************* */
void deleteFront(LL* myList)
{
    // Check if the LinkedList is empty
    if(myList->head == NULL)
    {
        printf("The LinkedList is empty. \n");
    }
    else
    {
        // Create a temporary pointer to the first node
        node* temp = myList->head;
        // Move the head pointer to the next node
        myList->head = myList->head->next;
        // Free the memory of the temporary node
        free(temp);
    } 
}

/*************************************************************************************************
 * Function 7 :       creates a function called search() that returns int
 *
 * Purpose:           To search for a provided number X in the LinkedList
 * 
 * Input:             LL* myList, int x
 ************************************************************************************************* */
int search(LL* myList, int x)
{
    // Start from the head of the LinkedList
    node* current = myList->head;
    // Traverse the LinkedList
    while (current != NULL)
    {
        // If the current node's data matches x, return 1
        if (current->x == x)
            return 1;
        // Move to the next node
        current = current->next;
    }
    // If no match is found after traversing the entire LinkedList, return 0
    return 0;
}


#endif