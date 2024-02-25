// Take a singly linked list as input and check if the linked list contains any duplicate value. You can assume that the maximum value will be 100.

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

void insert_at_end(Node *&head, Node *&tail, int val){
    // create head node 
    Node *newNode = new Node(val);
    
    // check head is null or not 
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
bool check_duplicate_node(Node *head, int num){
    Node *tmp = head;
    while(tmp != NULL){
        if(num == tmp->val){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
int main(){
    // create head and tail node initializes with null pointer 
    Node *head = NULL;
    Node *tail = NULL;
    while(1){
        cout<<"Enter 0 to exit!"<<endl;
        cout<<"Enter the node value: ";
        int num;
        cin>>num;
        if(num==0) break;
        // calling insert at end function 
        insert_at_end(head,tail,num);
    }
    // make copy of head node 
    Node *tmp = head;
    int flag = 0;
    while(tmp != NULL){
        flag = check_duplicate_node(tmp->next, tmp->val);
        if(flag == 1) break;
        tmp = tmp->next;
    }
    if(flag) cout<<"Yes duplicate value of node is found!"<<endl;
    else cout<<"No duplicate value of node is found!"<<endl;
    return 0;
}
