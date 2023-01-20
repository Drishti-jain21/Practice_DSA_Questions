// Get First and Last Node

#include "DoublyLL.h"

pair<DoublyNode*,DoublyNode*> getNodes(DoublyNode* head){
    if(head==NULL){
        pair<DoublyNode*, DoublyNode*> result;
        result->first = NULL;
        result->second = NULL;
        return result;
    }
    pair<DoublyNode*, DoublyNode*> result;
    result->first = head;
    DoublyNode* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    result->second = temp;
    return result;
}