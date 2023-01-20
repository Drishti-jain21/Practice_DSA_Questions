// Add at index k

#include "DoublyLL.h"

DoublyNode* addIndex(DoublyNode* head, int k, int value){
    if(head==NULL){
        head = new DoublyNode(value);
        return head;
    }
    if(k==0){
        DoublyNode* newNode = new DoublyNode(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    DoublyNode* temp = head;
    while(k!=1){
        temp = temp->next;
        k--;
    }
    DoublyNode* newNode = new DoublyNode(value);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;

}