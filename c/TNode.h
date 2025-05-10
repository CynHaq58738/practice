
#ifndef TNODE_H
#define TNODE_H

#include <stdio.h>
#include <stdlib.h>


/**********************************************************************************************
 * This program creates a TNode to use in the Binary Search Tree
 *
 * @name Cynthia Haque
 * @date 6-25-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define  TNode
typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
}tnode;

/*************************************************************************************************
 * Function 1 :       creates a function called makeTNode() that returns tnode*
 *
 * Purpose:           To create a tnode 
 *
 * Input:             int data
 * 
 * Output:            node* newTNode
 ************************************************************************************************* */
tnode* makeTNode(int data)
{ 
    tnode* newTNode = (tnode*) malloc(sizeof(tnode));
 
    newTNode->data = data;
    newTNode->left = NULL;
    newTNode->right = NULL;

    return newTNode; 
}


#endif
