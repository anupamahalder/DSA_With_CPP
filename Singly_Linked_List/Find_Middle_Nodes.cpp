/*
Question: Take a singly linked list as input and print the middle element. 
If there are multiple values in the middle print both.
*/

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
    // find the middle node of the linkedlist 
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL && fast->next != NULL){
        if(fast->next->next == NULL) break;
        fast = fast->next->next;
        slow = slow->next;  
    }
    if(fast->next==NULL){
        // means only one middle element exists 
        cout<<slow->val<<'\n';
    }
    else{
        // two middle element exists 
        cout<<slow->val<<" "<<slow->next->val<<'\n';
    }
    return 0;
}

/*
====================OUTPUT SECTION==========================
Input: 2 4 6 8 10 -1
Output: 6
----------------------------
Input: 2 4 5 6 8 10 -1
Output: 5 6
============================================================
*/
