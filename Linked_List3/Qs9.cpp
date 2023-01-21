// Add after node

#include "DoublyLL.h"

DoublyNode* addNode(DoublyNode* head, DoublyNode* ref, int value){
    if(head==NULL){
        head = new DoublyNode(value);
        return head;
    }
    DoublyNode* newNode = new DoublyNode(value);
    newNode->next = ref->next;
    newNode->prev = ref;
    ref->next->prev = newNode;
    ref->next = newNode;
    return head;
}