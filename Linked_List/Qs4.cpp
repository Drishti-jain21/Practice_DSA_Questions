// reversing the linked list

#include "linkedlist.h"

Node* reverseLL(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* newHead = reverseLL(head->next);
    Node* temp = newHead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return newHead;
}

// another method
Node* reverseLL2(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* newHead = reverseLL2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}