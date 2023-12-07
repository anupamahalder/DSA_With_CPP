// Doubly linked list create and print in reverse order

#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int val;
		Node* next;
        Node* prev;
	//constructor to initialize 
	Node(int val, Node* prev){
		this->val = val;
        this->prev = prev;
		this->next = NULL;
	}
};

void insert_node_with_tail(Node *&head, Node *&tail, Node *&prev, int val){
    // create a node 
    Node *newNode = new Node(val,prev);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    prev = newNode;
}
void print_linked_list(Node *head){
    if(head == NULL){
        cout<<"Linked list is empty!"<<endl;
        return;
    }
    cout<<"Your linked list is: "<<endl;
    Node *tmp = head;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
void print_linked_list_reverse(Node *head, Node *tail){
    if(tail == NULL){
        cout<<"Linked list is empty!"<<endl;
        return;
    }
    Node *tmp = tail;
    do{
        cout<<tmp->val<<" ";
        tmp = tmp->prev;
    }while(tmp != NULL);
    cout<<endl;
}

int main(){
    // create head and tail node initializes with null pointer 
    Node *head = NULL;
    Node *tail = NULL;
    Node *prev = head;
    while(1){
        cout<<"Enter -1 to exit!"<<endl;
        cout<<"Enter the node value: ";
        int num;
        cin>>num;
        if(num==-1) break;
        // calling insert at end function 
        insert_node_with_tail(head, tail,prev,num);
    }
    cout<<"The before sorting the linked list"<<endl;
    print_linked_list(head);

    cout<<"Print linked list in reverse order"<<endl;
    print_linked_list_reverse(head, tail);
    return 0;
}
