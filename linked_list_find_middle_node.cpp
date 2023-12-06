// Find the middle element of the singly linked list

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
int node_count(Node *head){
    if(head == NULL) return 0;
    Node *tmp = head;
    int cnt = 0;
    while(tmp != NULL){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
void middle_node(Node *head){
    int cnt = node_count(head);
    if(cnt == 0){
        cout<<"Linked list is empty\n";
    } 
    else{
        if(cnt%2==1) cnt++;
        Node *tmp = head;
        for(int i=0;i<cnt/2-1;i++){
            tmp = tmp->next;
        }
        cout<<tmp->val;
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
    cout<<"Middle element of the linked list is: "<<endl;
    middle_node(head);
    cout<<endl;
    return 0;
}
