// k reverse a linked list
#include "linkedlist.h"

Node* reverse(Node* head, int k){
    if (!head){
        return NULL;
    }  
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL){
        head->next = reverse(next, k);
    }
        
    return prev;
}
