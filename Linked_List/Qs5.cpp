// kth element from the end of the linked list

#include "linkedlist.h"

Node* kElement(Node* head, int k){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    
    for(int i=0;i<k;i++){
        temp = temp->next;
        if(temp==NULL){
            return NULL;
        }
    }
    while(temp->next!=NULL && temp!=NULL){
        temp = temp->next;
        head = head->next;
    }
    return head;

}