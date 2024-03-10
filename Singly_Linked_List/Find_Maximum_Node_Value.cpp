// Question: Take a singly linked list as input, then print the maximum value of them.
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
    // constructor 
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&head, Node *&tail, int val){
    // create a node 
    Node *newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
void printLinkedlist(Node *head){
    Node *tmp = head;
    cout<<"The list is: ";
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<"\n";
}

int maximumValue(Node *head){
    if(head==NULL) return -1;
    int ans = INT_MIN;
    Node *tmp = head;
    while(tmp != NULL){
        ans = max(ans, tmp->val);
        tmp = tmp->next;
    }
    return ans;
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    
    // create linked list 
    while(1){
        int x;
        cin>>x;
        if(x==-1) break;
        insertAtEnd(head, tail, x);
    }
    printLinkedlist(head);
    // print the maximum value of nodes
    int res = maximumValue(head);
    if(res == -1){
        cout<<"Create linked list first";
    }
    else{
        cout<<"The maximum value of linkedlist is: "<<res<<"\n";
    }
    return 0;
}

/*
==================OUTPUT SECTION=======================
Input: 8
      3
      4
      17
      -1
Output: 
The list is: 8 3 4 17 
The maximum value of linkedlist is: 17
--------------------------------------
Input: 8
      3
      7
      10
      6
      12
      9
      8
      -1
Output: 
The list is: 8 3 7 10 6 12 9 8 
The maximum value of linkedlist is: 12
=======================================================
*/
