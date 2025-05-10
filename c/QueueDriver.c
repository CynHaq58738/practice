#include <stdio.h>
#include "Queues.h"


/**********************************************************************************************
 * Driver program to test Queue operations using Doubly Linked List implementation.
 *
 * @name Cynthia Haque
 * @date 6-19-2024
 * @version 2024 CS2263
 **********************************************************************************************/

int main() 
{
    queues* myQueue = makeQueues();

    printf("After adding nodes: \n");
    enQueue(myQueue, 10);
    enQueue(myQueue, 20);
    enQueue(myQueue, 50);
    enQueue(myQueue, 70);

    printQueues(myQueue);

    int x = deQueue(myQueue);
    printf("Dequeued value: %d\n\n", x);

    printf("After removing a node: \n");
  
    printQueues(myQueue);

    free(myQueue);
    return 0;
}
