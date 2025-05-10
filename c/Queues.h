#ifndef QUEUES_H
#define QUEUES_H


#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


typedef struct Queues
{
    node *head;
    node *tail; 
} queues;

queues* makeQueues()
{
    queues *newQueue = (queues*) malloc(sizeof(queues));

    newQueue->head = NULL;
    newQueue->tail = NULL;

    return newQueue;
}


void enQueue(queues *myQueues, int data )
{
    if(!myQueues)
    {
        printf("Queue is NULL.\n");
        return;
    }

    node* current = (node*) malloc(sizeof(node));
    current->x = data;
    current->next = NULL;

    if(myQueues->tail)
    {
       myQueues->tail->next = current;
    }
    else
    {
        myQueues->head = current;
    }

    myQueues->tail = current;

}


int deQueue(queues *myQueues)
{
    if(!myQueues)
    {
        printf("Queue is NULL. \n");
        return -1;
    }

    if(!myQueues->head)
    {
        printf("Queue is empty. \n");
        return -1;
    }

    node *current = myQueues->head;
    int dequeuedValue = current->x;
    myQueues->head = myQueues->head->next;

    if(!myQueues->head)
    {
        myQueues->tail = NULL;
    } 

    free(current);
    return dequeuedValue;
}

void printQueues(queues *myQueues)
{
    if(!myQueues)
    {
        printf("Queue does not exist.\n");
        return;
    }

    if(!myQueues->head)
    {
        printf("Queue is empty.\n");
        return;
    }

    node *current = myQueues->head;
    while(current)
    {
        printf("%d\n", current->x);
        current = current->next;
    }
    printf("\n");
}


#endif