#ifndef DNODE_H
#define DNODE_H

#include <stdio.h>
#include <stdlib.h>


/**********************************************************************************************
 * This program creates a header file for the DNode in order 
 * to create a Doubly LinkedList
 *
 * @name Cynthia Haque
 * @date 6-19-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define a DNode 
typedef struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
}DNode;


//function declarations
DNode* makeDNode(int);

//define functions
/*************************************************************************************************
 * Function 1 :       creates a function called makeLL() that returns DNode*
 *
 * Purpose:           To create a DNode
 *
 * Input:             int x
 * 
 * Output:            DNode* current
 ************************************************************************************************* */
DNode* makeDNode(int x)
{
    DNode* current = (DNode*) malloc(sizeof(DNode));
    current->data = x;
    current->next = NULL;
    current->prev = NULL;

    return current;
}




#endif