// Add node to starting of linked list
#include "linkedlist.h"

Node* addFirst(Node* head,int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}

