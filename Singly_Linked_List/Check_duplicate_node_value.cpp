/*
Question: Take a singly linked list as input and check if the linkedlist contains
any duplicate value. You can assume that the maximum value will be 100.
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
    // check the duplicate element exists or not 
    int arr[102] = {0};
    bool ans = false;
    Node *tmp = head;
    while(tmp != NULL){
        int x = tmp->val;
        arr[x]++;
        if(arr[x]>1){
            // duplicate exists 
            ans = true;
            break;
        }
        tmp = tmp->next;
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

/*
==================OUTPUT SECTION==========================
Input: 5 4 8 6 2 1 -1
Output: NO
----------------------------
Input: 2 4 5 6 7 4 -1
Output: YES
==========================================================
*/
