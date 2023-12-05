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

void delete_head_node(Node *&head){
    if(head == NULL){
        cout<<"Linked is already empty!"<<endl<<endl;
        return;
    }
    // save head node then delete 
    Node *deleteNode = head;
    // make new head node 
    head = head->next;
    // delete previous head node 
    delete deleteNode;
    cout<<"Successfully deleted head node!"<<endl<<endl;
}
void delete_node(Node *&head, int pos){
    if(pos==1){
        delete_head_node(head);
        return;
    }
    Node *tmp = head;
    for(int i=1;i<pos-1;i++){
        // traverse 
        tmp = tmp->next;
    }
    // save delete node to delete later 
    Node *deleteNode = tmp->next;
    // make connection 
    tmp->next = tmp->next->next;
    // delete the node 
    delete deleteNode;
    cout<<"Successfully deteted node at position "<<pos<<"!"<<endl<<endl;
}
void delete_last_node(Node *&head){
    if(head == NULL){
        cout<<"Linked list is empty!"<<endl<<endl;
        return;
    }
    Node *tmp = head;
    if(head->next == NULL){
        head = NULL;
        delete tmp;
        cout<<"Deleted last node successfully!"<<endl<<endl;
        return;
    }
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    // save last node 
    Node *deleteNode = tmp->next;
    tmp->next = NULL;
    // tmp is now at last node 
    delete deleteNode;
    cout<<"Deleted last node successfully!"<<endl<<endl;
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
