#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "Node.h"
#include <stdbool.h>


/**********************************************************************************************
 * This program creates a header file for the Stack in order to create a Stack
 *
 * @name Cynthia Haque
 * @date 6-17-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

//define LinkedList
typedef struct Stack
{
    node *top;
}stack; 


//function declarations
stack* makeStack();
void push(stack*, int);
int pop(stack*);
int peek(stack*);
bool isEmpty(stack*)

//define functions
/*************************************************************************************************
 * Function 1 :       creates a function called makeStack() that returns stack*
 *
 * Purpose:           To create a stack
 *
 * Input:             none
 * 
 * Output:            stack* current
 ************************************************************************************************* */
stack* makeStack()
{
    stack *current = (stack*) malloc(sizeof(stack));
    current->top = NULL;

    return current;
}

/*************************************************************************************************
 * Function 2 :       creates a function called push() that returns void
 *
 * Purpose:           To insert into a stack
 * 
 * Input:             stack* myStack, int value
 ************************************************************************************************* */
void push(stack* myStack, int value)
{
    node *newNode = (node*) malloc(sizeof(node));
    newNode->x = value;
    newNode->next = myStack->top;
    myStack->top = newNode;
}

/*************************************************************************************************
 * Function 3 :       creates a function called pop() that returns int
 *
 * Purpose:           To remove a stack
 * 
 * Input:             stack *myStack 
 ************************************************************************************************* */
int pop(stack *myStack)
{
    int result;
    node *oldTop;
    oldTop = myStack->top;

    myStack->top = myStack->top->next;
    result = oldTop->x;

    freeNode(oldTop);
    return result;
}

/*************************************************************************************************
 * Function 4 :       creates a function called peek() that returns int*
 *
 * Purpose:           To look at the top of the stack
 * 
 * Input:             stack *myStack 
 ************************************************************************************************* */
int* peek(stack* myStack)
{
    if (!isEmpty(myStack)) 
    {
        return myStack->top->x;
    } else 
    {
        printf("Stack is empty.\n");
        return 1;
    }

}

/*************************************************************************************************
 * Function 5 :       creates a function called isEmpty() that returns bool
 *
 * Purpose:           To check if the stack is empty
 * 
 * Input:             stack *myStack 
 ************************************************************************************************* */
bool isEmpty(stack* myStack)
{
    return myStack->top == NULL;
}

#endif