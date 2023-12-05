// Take a singly linked list as input and print the size of the linked list.

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

void insert_at_end(Node *&head, int val){
    // create head node 
    Node *newNode = new Node(val);
    
    // check head is null or not 
    if(head == NULL){
        head = newNode;
    }
    else{
        Node *tmp = head;
        while(tmp->next != NULL){
            // traverse to reach at last position 
            tmp =  tmp->next;
        }
        // add newNode to the last node 
        tmp->next = newNode;
    }
}

int node_count(Node *head){
    Node *tmp = head;
    int cnt=0;
    while(tmp != 0){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
int main(){
    // create head node initializes with null pointer 
    Node *head = NULL;
    while(1){
        cout<<"Enter 0 to exit!"<<endl;
        cout<<"Enter the node value: ";
        int num;
        cin>>num;
        if(num==0) break;
        // calling insert at end function 
        insert_at_end(head,num);
    }
    cout<<"The size of linked list is: "<<node_count(head)<<endl;
    return 0;
}
