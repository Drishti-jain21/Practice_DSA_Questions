// printing doubly linked list in forward and backward manner

#include "DoublyLL.h"

void print(DoublyNode* head){
    if(head==NULL){
        return;
    }
    DoublyNode* temp = head;
    while(temp->next){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<tenp->data;
    cout<<endl;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    return;
}