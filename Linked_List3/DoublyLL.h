#include<iostream> 
using namespace std;

class DoublyNode{
    public:
    int data;
    DoublyNode *next;
    DoublyNode *prev;

    DoublyNode(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};


