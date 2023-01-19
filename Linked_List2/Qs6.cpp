/* intersection of linked list using difference method
theory - find length of both linked list
find difference of both linked list lengths
traverse the bigger linked list after difference nodes so that both linked list
traverse same amount of nodes
*/

#include<iostream>
using namespace std;
#include"Linked_list.h"

Node* intersection(Node* head1,Node* head2){
    if(head1==NULL||head2==NULL){
        return NULL;
    }
    Node* temp = head1;
    int length1 = 0;
    while(temp){
        temp = temp->next;
        length1++;
    }
    temp = head2;
    int length2 = 0;
    while(temp){
        temp = temp->next;
        length2++;
    }
    int d = abs(length1-length2);
    if(length1>length2){
        temp = head1;
        while(length1!=0){
            temp = temp->next;
            length1--;
        }
        while(temp&&head2){
            if(temp->data==head2->data){
                return temp;
            }
            temp = temp->next;
            head2= head2->next;
        }
        return NULL;
    }
    else{
        temp = head2;
        while(length2!=0){
            temp = temp->next;
            length2--;
        }
        while(temp&&head1){
            if(temp->data==head1->data){
                return temp;
            }
            temp = temp->next;
            head1 = head1->next;
        }
        return NULL;
    }

}