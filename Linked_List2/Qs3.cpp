// merge sort linked list
#include<iostream>
using namespace std;
#include"Linked_list.h"

Node* midPoint(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast = (fast->next)->next;
        slow = slow->next;
    }
    return slow;
}
Node* mergeTwo(ListNode* l1, ListNode* l2){
    Node* result = NULL;
    if(l1->val<l2->val){
        result = l1;
        l1 = l1->next;
        result->next = NULL;
    }
    else{
        result = l2;
        l2 = l2->next;
        result->next = NULL;
    }
    ListNode* temp = result;
    while(l1!=NULL&&l2!=NULL){
        if(l1->val>l2->val){
            temp->next = l2;
            l2 = l2->next;
        }
        else{
            temp->next = l1;
            l1 = l1->next;
        }
        temp = temp->next;
    }
    if(l1!=NULL){
        temp->next = l1;
    }
    else if(l2!=NULL){
        temp->next = l2;
    }
    return result;
    }
Node* sortList(Node* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* mid = midPoint(head);
    Node* temp = mid->next;
    mid->next = NULL;
    Node* l1 = sortList(head);
    Node* l2 = sortList(temp);
    head = mergeTwo(l1,l2);
    return head;
}