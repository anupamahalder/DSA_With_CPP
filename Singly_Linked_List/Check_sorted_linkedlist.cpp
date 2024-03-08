/*
Question: Take a singly linked list as input and check if the 
linked list is sorted in ascending order.
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
void insertAtHead(Node *&head,Node *&tail, int val){
    // create a new Node 
    Node *newNode = new Node(val);
    if(head==NULL){
        // insert at head 
        head = newNode;
        tail = head;
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
bool checkSorted(Node *head){
    if(head==NULL || head->next==NULL) return 1;
    Node *prev = head;
    Node *curr = head->next;
    while(curr!=NULL && curr->next!=NULL){
        if(prev->val >= curr->val) return false;
        prev = prev->next;
        curr = curr->next;
    }
    return true;
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
        // insertAtHead(head, tail, x);
        insertAtTail(head, tail, x);
    }
    // check the linkedlist is sorted or not 
    if(checkSorted(head)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

/*
===================OUTPUT SECTION======================
Input: 1 5 6 8 9 -1
Output: YES
----------------------------
Input: 2 4 6 5 8 4 -1
Output: NO
=======================================================
*/
