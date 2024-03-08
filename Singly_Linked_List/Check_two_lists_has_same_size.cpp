/*
Question: Take two singly linked lists as input and check if their sizes are same or not.
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
void inputToList(Node *&head, Node *&tail){
    while(1){
        int x;
        cin>>x;
        if(x==-1) break;
        insertAtTail(head, tail, x);
    }
}
bool checkSameSize(Node *head1, Node *head2){
    Node *tmp1 = head1;
    Node *tmp2 = head2;
    while(tmp1 != NULL && tmp2 != NULL){
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    if(tmp1==NULL && tmp2==NULL) return 1;
    return 0;
}
int main(){
    // create head and tail node assigning null for first linkedlist 
    Node *head1  = NULL;
    Node *tail1 = NULL;
    // create head and tail node assigning null for second linkedlist 
    Node *head2  = NULL;
    Node *tail2 = NULL;
    // take input to the first singly linkedlist 
    inputToList(head1, tail1);
    
    // take input to the second singly linkedlist 
    inputToList(head2, tail2);

    // check both linked list has same sizes or not
    if(checkSameSize(head1,head2)) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}

/*
================OUTPUT SECTION======================
Input:
      2 1 5 3 4 9 -1
      1 2 3 4 5 6 -1
Output: YES
----------------------------
Input:
      5 1 4 5 -1
      5 1 4 -1
Output: NO
====================================================
*/
