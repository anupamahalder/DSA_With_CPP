// Take a singly linked list as input and print the size of the linked list where -1 means end of the input.

#include<bits/stdc++.h>
using namespace std;

// Class to create a singly linkedlist node 
class Node{
    public:
        int val;
        Node* next;
    // constructor 
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
// for O(1) time complexity 
void insertAtHead(Node *&head, int val){
    // create a new Node 
    Node *newNode = new Node(val);
    if(head==NULL){
        // insert at head 
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}
// for O(1) time complexity 
void insertAtTail(Node *&head, Node *&tail, int val){
    // create a new node 
    Node *newNode = new Node(val);
    if(head == NULL){
        // list is empty 
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    // update the tail node 
    tail = newNode;
}
int main(){
    // create head node assigning null 
    Node *head  = NULL;
    Node *tail = NULL;
    // take input to the singly linkedlist 
    while(1){
        int x;
        cin>>x;
        if(x==-1) break;
        // we can insert using any of the function either insert at head or tail
        // insertAtHead(head, x);
        insertAtTail(head, tail, x);
    }
    // count the total nodes of the list 
    int count = 0;
    Node *tmp = head;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    cout<<count<<'\n';
    return 0;
}

/*
========================OUTPUT SECTION==========================
Input:
      2 1 5 3 4 8 9 -1
Output: 7
------------------------------------
Input: 
      5 1 4 5 -1
Output: 4
================================================================
*/
