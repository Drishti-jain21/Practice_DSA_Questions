// find the middle of linked list

#include "linkedlist.h"

Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast->next!=NULL && fast!=NULL){
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}