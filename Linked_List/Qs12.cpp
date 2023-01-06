// add two numbers

#include "linkedlist.h"
Node* addTwoNumbers(Node* l1, Node* l2) {
    if(l1==NULL&&l2==NULL){
        return NULL;
    }
    if(l1==NULL){
        if(l2->data>=10){
            l2->data=l2->data%10;
            if(l2->next!=NULL){
                l2->next->data++;
            }
            else{
                Node* finalNode = new Node(1);
                l2->next = finalNode;
                return l2;
            }
        }
        Node* newNode = addTwoNumbers(NULL,l2->next);
        return l2;
    }
    if(l2==NULL){
        if(l1->dat>=10){
            l1->data=l1->data%10;
            if(l1->next!=NULL){
                l1->next->data++;
            }
            else{
                Node* finalNode = new Node(1);
                l1->next = finalNode;
                return l1;
            }

        }
        Node* newNode = addTwoNumbers(l1->next,NULL);
        return l1;
    }
    Node* finalNode = NULL;
    int result = l1->data+l2->data;
    if(result>=10){
        finalNode = new Node(result%10);
        if(l1->next!=NULL){
            if(l1->next!=NULL){
                l1->next->data++;
            }
            else{
                Node* newNode = new Node(1);
                finalNode->next = newNode;
                return finalNode;
            }
        }
        else{
            if(l2->next!=NULL){
                l2->next->data++;
            }
            else{
                Node* newNode = new Node(1);
                finalNode->next = newNode;
                return finalNode;
            }
        } 
    }
    else{
        finalNode = new Node(result);
    }
    Node* newNode = addTwoNumbers(l1->next,l2->next);
    finalNode->next = newNode;
    return finalNode;
    }