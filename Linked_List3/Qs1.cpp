// Add first in doubly linked list
#include "DoublyLL.h"

DoublyNode* addFirst(DoublyNode* head,int value){
    if(head==NULL){
        head = new DoublyNode(value);
        return head;
    }
    DoublyNode* newNode = new DoublyNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}