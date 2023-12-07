// Take input of doubly linked list and print the list and also print in reverse order
// Insert node at beginning, end or any given position
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
void insert_at_head(Node *&head, Node *&tail, int val){
    // create a node 
    Node *newNode = new Node(val,tail);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node *tmp = head;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    tail = newNode;
}

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
void insert_at_pos(Node *&head, Node *&tail, int val, int pos){
    // create a node 
    Node *newNode = new Node(val,tail);
    if(pos == 1 && head==NULL){
        head = newNode;
        tail = newNode;
    }
    else if(pos == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else{
        Node *tmp = head;
        // pos always less than or equal to the size of linked list 
        for(int i=1;i<pos-1;i++){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        newNode->prev = tmp;
        tmp->next = newNode;
    }
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
    while(1){
        cout<<"Enter -1 to exit!"<<endl;
        cout<<"Enter the node value: ";
        int num;
        cin>>num;
        if(num==-1) break;
        // calling insert at end function 
        // insert_at_head(head, tail,num);
        insert_node_at_tail(head, tail, num);
    }
    cout<<"The linked list"<<endl;
    print_linked_list(head);
    int pos;
    cout<<"Enter position:";
    cin>>pos;
    cout<<"Enter the node value: ";
    int num;
    cin>>num;
    insert_at_pos(head, tail, num, pos);
    cout<<"The After inserting node to the linked list"<<endl;
    print_linked_list(head);
    cout<<"Print linked list in reverse order"<<endl;
    print_linked_list_reverse(head, tail);
    return 0;
}
