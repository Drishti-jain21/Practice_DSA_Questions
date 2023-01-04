// Add node at index i
#include "linkedlist.h"

Node* addAtIndex(Node* head,int data,int index){
    if(head==NULL||index==0){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    else{
        Node* temp = head;
        while(index!=1){
            temp=temp->next;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
}

