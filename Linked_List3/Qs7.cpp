// Remove at index k

#include "DoublyLL.h"

DoublyNode* removeIndex(DoublyNode* head, int k){
    if(head==NULL){
        return NULL;
    }
    if(k==0){
        head = head->next;
        head->prev = NULL;
    }
    DoublyNode* temp = head;
    while(k!=1){
        if(temp==NULL){
            return NULL;
        }
        temp = temp->next;
        k--;
    }
    temp->next = temp->next->next;
    temp->next->prev = temp;
    return head;
}