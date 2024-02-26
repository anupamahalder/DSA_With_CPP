// ---------------Linked List--------- 
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int val;
		Node* next;
	//constructor to initialize 
	Node(int val){
		this->val = val;
		this->next = NULL;
	}
};
int main(){
    // create head node 
    Node *head = new Node(5);
    Node *a = new Node(10);
    Node *b = new Node(15);

    //link each node 
    head->next = a;
    a->next = b;

    //print the value of linked list
    // create a Node type pointer to point where head is pointing 
    Node *tmp = head;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        // make the pointer to point next node 
        tmp = tmp->next;
    }
    return 0;
}
