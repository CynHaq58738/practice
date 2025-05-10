#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "DNode.h"


/**********************************************************************************************
 * This program creates a header file for a DLinkedList in order to create a Doubly
 * LinkedList
 *
 * @name Cynthia Haque
 * @date 6-19-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define LinkedList
typedef struct DLinkedList
{
    DNode *head;
    DNode *tail;
}DLL;


//function declarations
DLL* makeDLL();
void insertAtEnd(DLL*, int);
void removeFirstOccurrence(DLL*, int);
void removeAllOccurrences(DLL*, int);
void printList(DLL*);


//define functions
/*************************************************************************************************
 * Function 1 :       creates a function called makeDLL() that returns DLL*
 *
 * Purpose:           To create a Doubly LinkedList
 *
 * Input:             none
 * 
 * Output:            DLL* current
 ************************************************************************************************* */
DLL* makeDLL()
{
    DLL* current = (DLL*) malloc(sizeof(DLL));
    current->head = NULL;
    current->tail = NULL;

    return current;
}


/*************************************************************************************************
 * Function 2 :       creates a function called insertAtEnd() that returns void
 *
 * Purpose:           To inserts a node at the end of the doubly LinkedList
 * 
 * Input:             DLL* myList, int data
 ************************************************************************************************* */
void insertAtEnd(DLL* myList, int data)
{
    DNode* newNode = makeDNode(data);
    
    if(myList->head == NULL)
    {
        myList->head = newNode;
        myList->tail = newNode;
    }
    else
    {
        myList->tail->next = newNode;
        newNode->prev = myList->tail;
        myList->tail = newNode;
    }
}


/*************************************************************************************************
 * Function 3 :       creates a function called removeFirstOccurrence() that returns void
 *
 * Purpose:           To remove the element that occurs first
 * 
 * Input:             DLL* myList, int data
 ************************************************************************************************* */
void removeFirstOccurrence(DLL* myList, int data)
{
    DNode *current = myList->head;

    while(current !=NULL)
    {
        if(current->data == data)
        {
            if(current->prev !=NULL)
            {
                current->prev->next = current->next;
            }
            if (current->next !=NULL)
            {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
    }
    current = current->next;
}


/*************************************************************************************************
 * Function 4 :       creates a function called removeAllOccurrences() that returns void
 *
 * Purpose:           To remove all copies in the list that appear
 * 
 * Input:             DLL* myList, int data
 ************************************************************************************************* */
void removeAllOccurrences(DLL* myList, int data)
{
    DNode *current = myList->head;

    while(current !=NULL)
    {
        if(current->data == data)
        {
            if (current->prev != NULL) 
            {
                current->prev->next = current->next;
            } 
            else 
            {
                // This is the head of the list
                myList->head = current->next;
            }

            if (current->next != NULL) 
            {
                current->next->prev = current->prev;
            } 
            else 
            {
                // This is the tail of the list
                myList->tail = current->prev;
            }
            DNode* next = current->next;
            free(current);
            current = next;
        } 
        else 
        {
            current = current->next;
        }
    }
}


/*************************************************************************************************
 * Function 5 :       creates a function called printList() that returns void
 *
 * Purpose:           To print the Doubly Linked List
 * 
 * Input:             DLL* myList
 ************************************************************************************************* */
void printList(DLL *myList)
{
    DNode* current = myList->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


#endif