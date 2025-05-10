
#include "DLinkedList.h"

/**********************************************************************************************
 * This program creates a Driver to test the functions in the DLinkedList.h file
 *
 * @name Cynthia Haque
 * @date 6-19-2024
 * @version 2024 CS2263
 ********************************************************************************************** */

int main() 
{
    DLL* list = makeDLL();
    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
    insertAtEnd(list, 20);

    printf("List after insertions:\n");
    printList(list);
    

    removeFirstOccurrence(list, 20);
    printf("List after removing first occurrence of 20:\n");
    printList(list);

    removeAllOccurrences(list, 20);
    printf("List after removing all occurrences of 20:\n");
    printList(list);

    free(list);

    return 0;
}