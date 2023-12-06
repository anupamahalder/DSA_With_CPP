// Find middle node of a singly linked list

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

Node* middle_node(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node *fast = head;
    Node *slow = head;
    while(slow != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }
    }
    return slow;
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

    Node *mid = middle_node(head);
    cout<<"Middle element of the linked list is: "<<endl;
    if(mid != NULL) cout<<mid->val<<endl;
    else cout<<"Linked list is empty"<<endl;
    return 0;
}
