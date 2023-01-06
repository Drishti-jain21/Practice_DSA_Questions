// fold a linked list

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

Node* fold(Node* head){
    if(head->next->next==NULL){
        return head;
    }
    Node* temp = head;
    Node* fast = head;
    Node* end = NULL;
    while(fast!=NULL && fast->next!=NULL){
        temp = temp->next;
        end = temp;
        fast = (fast->next)->next;
    }
    end->next = NULL;
    temp = reverse(temp);
    while(head){
        fast = temp->next;
        temp->next = head->next;
        head->next = temp;
        temp = fast;
        head = head->next;
    }
    if(temp){
        end->next=temp;
    }
    return head;

}