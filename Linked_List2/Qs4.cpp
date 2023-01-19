// segregate even/odd nodes
// 1->2->3->4
// 2->4->1->3

#include<iostream>
using namespace std;
#include"Linked_list.h"

Node* oddEven(Node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node* result = oddEven(head->next);
	int value = result->val;
	int value2 = head->val;
    if (value%2==0) {
      	if (value2%2!=0){
		  	Node* temp = result->next;
		  	if(temp==NULL){
			  	result->next = head;
			  	head->next = NULL;
			  	return result;
		  	}
			temp = result;
          	while (temp->next!=NULL && (temp->next->val%2==0)) {
                temp = temp->next;
            }
			head->next = temp->next;
			temp->next = head;
        	return result;

        }
		else{
			head->next = result;
			return head;
		}
    }
	return head;

}
