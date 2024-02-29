// Sorting linked list in ascending order

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

void insert_node_with_tail(Node *&head, Node *&tail, int val){
    // create a node 
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
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
void sorting_linked_list(Node *head){
    for(Node *i=head;i->next!=NULL;i=i->next){
        for(Node *j=i->next;j!=NULL;j=j->next){
            // swap 
            if(i->val > j->val){
                swap(i->val,j->val);
            }
        }
    }
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
        insert_node_with_tail(head, tail,num);
    }
    cout<<"The before sorting the linked list"<<endl;
    print_linked_list(head);
    cout<<"Linked list in after soting:"<<endl;
    sorting_linked_list(head);
    print_linked_list(head);
    return 0;
}
