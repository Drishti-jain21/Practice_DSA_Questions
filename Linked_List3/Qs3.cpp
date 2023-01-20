// Remove Last Node in Doubly Linked List
#include "DoublyLL.h"

DoublyNode* removeLast(DoublyNode* head){
    if(head==NULL){
        return NULL;
    }
    DoublyNode* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    (temp->prev)->next = NULL;
    return head;
}