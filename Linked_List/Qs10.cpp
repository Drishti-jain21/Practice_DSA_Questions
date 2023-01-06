// is Linked list a palindrome

#include "linkedlist.h"

Node* reverse(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool palindrome(Node* head){
    if(head->next->next==NULL){
        if(head->data==head->next->data){
            return true;
        }
        return false;
    }
    Node* temp = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        temp = temp->next;
        fast = (fast->next)->next;
    }
    temp = reverse(temp);
    while(temp!=NULL){
        if(head->data!=temp->data){
            return false;
        }
        head = head->next;
        temp = temp->next;
    }
    return true;
}