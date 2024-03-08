/*
Question: Take a singly linked list as input, then take q queries. 
In each query you will be given an index and value. You need to insert
those values in the given index and print the linked list. 
If the index is invalid print “Invalid”.
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
int nodeCount(Node *head){
    Node *tmp = head;
    int count = 0;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}
void printList(Node *head){
    Node *tmp = head;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<"\n";
}
void insertAtIndex(Node *&head, int val, int index){
    // create new node 
    Node *newNode = new Node(val);
    Node *tmp = head;
    for(int i=0;i<index-1;i++){
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
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
    int q;
    cin>>q;
    while(q--){
        int index, val;
        // take index as input 
        cin>>index>>val;
        // validate index 
        int totalNode = nodeCount(head);
        if(index < 0 || index > totalNode){
            cout<<"Invalid\n";
        }
        else{
            // insert at given index 
            if(index==0) insertAtHead(head, tail, val);
            else if(index==totalNode) insertAtTail(head, tail, val);
            else insertAtIndex(head, val, index);
            // print the linked list 
            printList(head);
        }
    }
    return 0;
}

/*
================OUTPUT SECTION==========================
Input: 10 20 30 -1
        7
        1 40
        5 50
        4 50
        0 100
        7 40
        1 110
        7 40
Output:
      10 40 20 30 
      Invalid
      10 40 20 30 50 
      100 10 40 20 30 50 
      Invalid
      100 110 10 40 20 30 50 
      100 110 10 40 20 30 50 40 

========================================================
*/
