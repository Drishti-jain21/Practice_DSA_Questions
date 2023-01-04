//Remove last node from linked list
#include "linkedlist.h"

Node* removeLast(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}