// remove after given node

#include "DoublyLL.h"

DoublyNode* removeAfter(DoublyNode* head, DoublyNode* ref){
    if(head==NULL||ref==NULL){
        return NULL;
    }
    ref->next = ref->next->next;
    ref->next->prev = ref;
    return head;
}