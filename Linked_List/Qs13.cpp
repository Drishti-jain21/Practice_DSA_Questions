// find the intersection point of two linked list
#include "linkedlist.h"

// method 1
Node* intersection(Node* head1, Node* head2){
    if(head1==NULL||head2==NULL){
        return NULL;
    }
    if(head1->data==head2->data){
        return head1;
    }
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1==temp2){
            return temp1;
        }
        if(!temp1){
            temp1 = head2;
        }
        if(!temp2){
            temp2 = head1;
        }
    }
    return temp1;
}

//method 2
Node* intersection(Node* head1, Node* head2){
    if(headA==NULL||headB==NULL){
        return NULL;
    }    
    unordered_map<ListNode*,bool> p;
    while(headA){
        p[headA] = true;
        headA = headA->next;
    }
    while(headB){
        if(p.count(headB)>0){
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

