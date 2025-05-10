#ifndef STACK_H
#define STACK_H

#include "DLinkedList.h"

/**********************************************************************************************
 * This file provides implementations of functions for a Stack using a Doubly Linked List.
 *
 * @name Cynthia Haque
 * @date 6-19-2024
 * @version 2024 CS2263
 **********************************************************************************************/

//define a stack
typedef struct stack
{
    DNode* top;
} Stack;

//define prototypes
Stack* createStack();
void push(Stack*, int );
int pop(Stack*);
int peek(Stack*);
int isEmpty(Stack*);



/**********************************************************************************************
 * Function 1 :       creates a function called createStack() that returns Stack*
 *
 * Purpose:           To create a new Stack
 *
 * Input:             none
 * 
 * Output:            Stack* stack
 ************************************************************************************************* */
Stack* createStack() 
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

/**********************************************************************************************
 * Function 2 :       creates a function called push() that returns void
 *
 * Purpose:           To push an element onto the Stack
 *
 * Input:             Stack* stack, int data
 * 
 * Output:            none
 ************************************************************************************************* */
void push(Stack* stack, int data) 
{
    DNode* newNode = makeDNode(data);
    if (newNode != NULL) 
    {
        newNode->next = stack->top;
        stack->top = newNode;
    } 
}

/**********************************************************************************************
 * Function 3 :       creates a function called pop() that returns int
 *
 * Purpose:           To pop an element from the Stack
 *
 * Input:             Stack* stack
 * 
 * Output:            int data (popped element)
 ************************************************************************************************* */
int pop(Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stack is empty.\n");
    }
    DNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

/**********************************************************************************************
 * Function 4 :       creates a function called peek() that returns int
 *
 * Purpose:           To peek the top element of the Stack without removing it
 *
 * Input:             Stack* stack
 * 
 * Output:            int data (top element)
 ************************************************************************************************* */
int peek(Stack* stack) 
{
    if (isEmpty(stack))
    {
        printf("Error: Stack is empty.\n");
        return stack->top->data;
    }
}

/**********************************************************************************************
 * Function 5 :       creates a function called isEmpty() that returns int
 *
 * Purpose:           To check if the Stack is empty
 *
 * Input:             Stack* stack
 * 
 * Output:            1 if empty, 0 if not empty
 ************************************************************************************************* */
int isEmpty(Stack* stack)
{
    return stack->top == NULL;
}

/**********************************************************************************************
 * Function 6 :       creates a function called printStack() that returns void
 *
 * Purpose:           To print the elements of the Stack
 *
 * Input:             Stack* stack
 * 
 * Output:            none
 ************************************************************************************************* */
void printStack(Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    DNode* current = stack->top;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

#endif