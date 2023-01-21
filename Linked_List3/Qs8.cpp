// add before given node

#include "DoublyLL.h"

DoublyNode* addBefore(DoublyNode* head, DoublyNode* ref, int value){
    if(head==NULL){
        head = new DoublyNode(value);
        return head;
    }
    if(ref==head){
        DoublyNode* newNode = new DoublyNode(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    DoublyNode* newNode = new DoublyNode(value);
    newNode-> prev = ref->prev;
    newNode->next = ref;
    ref->prev = newNode;
    newNode->prev->next = newNode;
    return head;
}