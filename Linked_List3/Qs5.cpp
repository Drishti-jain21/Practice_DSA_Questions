// get Node at index k
#include "DoublyLL.h"

int getNode(DoublyNode* head, int k){
    if(head==NULL){
        return -1;
    }
    if(k<0){
        return -1;
    }
    if(k==0){
        return head->data;
    }
    DoublyNode* temp = head;
    while(temp){
        temp = temp->next;
        k--;
        if(k==0){
            return temp->data;
        }
    }
    return -1;
}