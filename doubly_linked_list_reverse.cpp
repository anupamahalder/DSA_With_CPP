// Sorting linked list in ascending order

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
		this->next = nullptr;
	}
};

void insert_node_at_tail(Node *&head, Node *&tail, int val){
    // create a node 
    Node *newNode = new Node(val,tail);
    if(head == nullptr){
        head = newNode;
    }
    else{
        tail->next = newNode;
    }
    tail = newNode;
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

void reverseLinkedlist(Node *&head, Node *&tail){
    if(head == NULL || head->next == NULL) return;
    Node *tmp = head;
    while(tmp != NULL){
        swap(tmp->next, tmp->prev);
        tmp = tmp->prev;
    }
    swap(head, tail);
}

int main(){
    // create head and tail node initializes with null pointer 
    Node *head = NULL;
    Node *tail = NULL;
    while(1){
        cout<<"Enter -1 to exit!"<<endl;
        cout<<"Enter the node value: ";
        int num;
        cin>>num;
        if(num==-1) break;
        // calling insert at end function 
        insert_node_at_tail(head, tail, num);
    }
    print_linked_list(head);
    reverseLinkedlist(head, tail);
    cout<<"The reverse linked list: "<<endl;
    print_linked_list(head);
    return 0;
}
