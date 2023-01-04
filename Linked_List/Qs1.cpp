// Add node to starting of linked list
#include<iostream> 
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }

};

Node* addFirst(Node* head,int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}

