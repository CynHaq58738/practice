#ifndef NODE2_H
#define NODE2_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
   double x;
   char opp;
   bool isChar;
   struct Node *next ;
}node;


node* createNode(double data)
{
   node* newNode = (node*) malloc(sizof(node));
   newNode->x = data;
   newNode->isChar = false;
   newNode->next = NULL;
   
   return newNode;
}

node* createCharNode(char data)
{
   node* newNode = (node*) malloc(sizeof(node));
   newNode->opp = data;
   newNode->isChar = false;
   newNode->next = NULL;
   
   return newNode;
}




