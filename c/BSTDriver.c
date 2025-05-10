#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"


/**********************************************************************************************
 * This program creates a driver to create a Binary Search Tree 
 *
 * @name Cynthia Haque
 * @date 6-26-2024
 * @version 2024 CS2263
 ********************************************************************************************** */
int main()
{
    //create a BST
    BST *myBST = makeBST();
    
    //insert nodes into the BST
    myBST->root = insert(myBST->root, 5);
    myBST->root = insert(myBST->root, 1);
    myBST->root = insert(myBST->root, 10);
    myBST->root = insert(myBST->root, 9);
    myBST->root = insert(myBST->root, 4);
    myBST->root = insert(myBST->root, 2);
    
    //print tree 
    printf("Inserted nodes in Binary Search Tree: \n");
    printTreeInLNR(myBST->root);

    printf("\n");

    //create a variable to store user input
    char choice;

    //create a variable to store the data
    int data;

    //print after searching for the BST
    do
    {
        printf("Enter a number to search for:\n");
        scanf("%d", &data);

        //consume newline character
        scanf("%*c");

        //search through the BST
        tnode *current = search(myBST->root, data);

        if(current)
        {
            printf("Found %d in BST.\n", data);
        }
        else
        {
            printf("Could not find %d in BST.\n", data);
        }

        printf("Do you want to search again? (y/n):\n");
        scanf("%c", &choice);
    
    }while(choice == 'y' || choice == 'Y');


    //Delete a tnode
    deleteTnode(myBST->root, 10);

    printf("\n");

    //print out the BST after deleting the tnode
    printf("After deleting the tnode 10: \n");
    printTreeInLNR(myBST->root);

    free(myBST->root);

    return 0;
}