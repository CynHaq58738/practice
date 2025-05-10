#include <stdio.h>
#include "Stack.h"

/**********************************************************************************************
 * Driver program to test Stack operations using Doubly Linked List implementation.
 *
 * @name Cynthia Haque
 * @date 6-19-2024
 * @version 2024 CS2263
 **********************************************************************************************/

int main() 
{
    Stack *stack = createStack();

    printf("Stack operations:\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Popped element from stack: %d\n", pop(stack));
    printf("Top element of stack: %d\n", peek(stack));

    return 0;
}
