// remove before given node

#include "DoublyLL.h"

DoublyNode* removeBefore(DoublyNode* head, DoublyNode* ref){
    if(head==NULL||ref==NULL){
        return NULL;
    }
    if(head==ref){
        return head;
    }
    if(ref==head->next){
        head = head->next;
        head->prev = NULL;
        return head;
    }
    ref->prev = ref->prev->prev;
    ref->prev->next = ref;
    return head;
}