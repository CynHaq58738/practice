#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>

#include "TNode.h"

/**********************************************************************************************
 * This program defines a Binary Search Tree 
 *
 * @name Cynthia Haque
 * @date 6-26-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define BST
typedef struct BinarySearchTree
{
    tnode *root; 
}BST;


//function declarations
BST* makeBST();
tnode* insert(tnode*, int);
tnode* search(tnode*, int);
void printTreeInLNR(tnode*);
tnode* deleteTnode(tnode*, int);


//define functions
/*************************************************************************************************
 * Function 1 :       creates a function called makeBST() that returns BST*
 *
 * Purpose:           To create a BST
 *
 * Input:             none
 * 
 * Output:            BST* newBST 
 ************************************************************************************************* */
BST* makeBST()
{
    BST* newBST = (BST*) malloc(sizeof(BST));
    newBST->root = NULL;

    return newBST;
}


/*************************************************************************************************
 * Function 2 :       creates a function called insert() that returns tnode*
 *
 * Purpose:           To add a node to the BST
 *
 * Input:             tnode* myTnode, int data
 * 
 * Output:            myTnode
 ************************************************************************************************* */
tnode* insert(tnode* myTnode, int data)
{
    if(myTnode == NULL)
    {
        makeTNode(data);
    }
    else if(data < myTnode->data)
    {
        myTnode->left = insert(myTnode->left, data);
    }
    else
    {
        myTnode->right = insert(myTnode->right, data);
    }
}


/*************************************************************************************************
 * Function 3 :       creates a function called search() that returns tnode*
 *
 * Purpose:           To search through the tnodes to find a number
 *
 * Input:             tnode* myTnode, int data
 * 
 * Output:            tnode* myTnode
 ************************************************************************************************* */
tnode* search(tnode* myTnode, int data)
{
    if(myTnode == NULL || data == myTnode->data)
    {
        return myTnode;
    }
    else if(data < myTnode->data)
    {
        return search(myTnode->left, data);
    }
    else 
    {
        return search(myTnode->right, data);
    }
    return myTnode;
}


/*************************************************************************************************
 * Function 4 :       creates a function called printTreeInLNR() that returns void
 *
 * Purpose:           To print the BST in LNR 
 *
 * Input:             tnode* myTnode
 ************************************************************************************************* */
void printTreeInLNR(tnode* myTnode)
{
    if(myTnode == NULL)
    return;

    //visit left sub-tree
    printTreeInLNR(myTnode->left);
    //print the data
    printf("%d\n", myTnode->data);
    //visit right sub-tree
    printTreeInLNR(myTnode->right);
}


/*************************************************************************************************
 * Function 5 :       creates a function called deleteNode() that returns tnode*
 *
 * Purpose:           To delete a tnode 
 *
 * Input:             tnode* myTnode, int data
 * 
 * Output:            myTnode
 ************************************************************************************************* */
tnode* deleteTnode(tnode* myTnode, int data)
{
    if(myTnode == NULL)
    {
        return NULL;
    }
    else if(data < myTnode->data)
    {
        myTnode->left = deleteTnode(myTnode->left, data);
    }
    else if(data > myTnode->data)
    {
        myTnode->right = deleteTnode(myTnode->right, data);
    }
    else
    {
        //Case 1: no children
        if(myTnode->left == NULL && myTnode->right == NULL)
        {
            free(myTnode);
            myTnode = NULL;
        }
        //Case 2: 1 child
        else if(myTnode->left == NULL)
        {
            tnode* current = myTnode->right;
            free(myTnode);
            return current;
        }
        else if(myTnode->right == NULL)
        {
            tnode* current = myTnode->left;
            free(myTnode);
            return current;
        }
        //Case 3: 2 children
        else
        {
            tnode* su = myTnode->right;
        
            // Find the successor
            while(su->left != NULL)
            {
                //su successor is is the tnode, so we swap their values 
                su->data = myTnode->data;
                su->data = data;
                //delete su
                myTnode->right = deleteTnode(myTnode->right, data);
                return myTnode;
            }
        }
    }
}


#endif