// merge sort in linked list
#include "linkedlist.h"

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1==NULL && head2==NULL){
        return NULL;
    }
    Node* fh=NULL;
    Node* ft=NULL;
    if((head2->data)>=(head1->data)){
        fh=head1;
        ft=head1;
        head1=head1->next;
    }
    else if((head2->data)<(head1->data)){
        fh=head2;
        ft=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if((head1->data)>(head2->data)){
            ft->next=head2;
            ft=ft->next;
            head2=head2->next;
        }
        else if((head2->data)>=(head1->data)){
            ft->next=head1;
            ft=ft->next;
            head1=head1->next;
        }
    }
    if(head1==NULL){
        ft->next=head2;
    }
    if(head2==NULL){
        ft->next=head1;
    }
    return fh;
}
Node *midPoint(Node *head){
    Node* slow = head;
    Node* fast = head;

    while(fast->next!=NULL && fast!=NULL){
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}
Node *mergeSort(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* mid=midPoint(head);
    Node* newhead=mid->next;
    mid->next=NULL;
    Node* head3=mergeSort(head);
    Node* head4=mergeSort(newhead);
    Node* finalhead=mergeTwoSortedLinkedLists(head3,head4);
    return finalhead;
}