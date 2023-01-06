// merge 2 sorted list

#include "linkedlist.h"

Node* mergeSorted(Node* head1, Node* head2){
    if(head1==NULL&&head2==NULL){
        return NULL;
    }
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
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