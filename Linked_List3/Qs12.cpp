// remove given node

#include "DoublyLL.h"

DoublyNode* removeNode(DoublyNode* head, DoublyNode* ref){
    if(head==NULL||ref==NULL){
        return NULL;
    }
    if(head==ref){
        head = head->next;
        head->prev = NULL;
        return head;
    }
    DoublyNode* prevNode = ref->prev;
    DoublyNode* nextNode = ref->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    return head;
}