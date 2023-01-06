// find the intersection point of two linked list
#include "linkedlist.h"

Node* intersection(Node* head1, Node* head2){
    if(head1==NULL||head2==NULL){
        return NULL;
    }
    if(head1->data==head2->data){
        return head1;
    }
    while (head2) {
        Node* temp = head1;
        while (temp) {
            if (temp == head2){
                return head2;
            }
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;

}