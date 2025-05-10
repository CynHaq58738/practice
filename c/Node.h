#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>


/**********************************************************************************************
 * This program creates a header file in order to run the Main.c file
 *
 * @name Cynthia Haque
 * @date 6-14-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define node
typedef struct Node
{
    int x;
    struct Node *next;
}node;


//function declarations
node* makeNode(int);
void printNode(node*);

//define functions
/*************************************************************************************************
 * Function 1 :       creates a function called makeNode() that returns node*
 *
 * Purpose:           To create a node 
 *
 * Input:             int data
 * 
 * Output:            node* newNode
 ************************************************************************************************* */
node* makeNode(int data)
{
    node* newNode = (node*) malloc(sizeof(node));

    newNode->x = data;
    newNode->next = NULL;

    return newNode;
}


/*************************************************************************************************
 * Function 2 :       creates a function called printNode() that returns void
 *
 * Purpose:           To print a node
 * 
 * Input:             node* current
 ************************************************************************************************* */
void printNode(node* current)
{
    printf("My nodes x is %d \n", current->x);
    if(current->next == NULL)
    {
        printf("The is no next node. \n");
    }
    else
    {
        printf("My nodes next is %d \n", current->next);
    }
}







#endif