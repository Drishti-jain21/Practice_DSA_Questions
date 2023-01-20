// Remove the first node in doubly linked list

#include "DoublyLL.h"

DoublyNode* removeFirst(DoublyNode* head){
    if(head==NULL){
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
    return head;
}