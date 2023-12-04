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
void insert_at_beginning(Node *&head, int val){
    // create head node 
    Node *newNode = new Node(val);
    
    // check head is null or not 
    if(head == NULL){
        head = newNode;
    }
    else{
        // make a pointer to point the head node 
        Node *tmp = head;
        // now our head will be newNode 
        head = newNode;
        // make link the new head node to other nodes 
        head->next = tmp;
    }
    cout<<"Successfully inserted at beginning!"<<endl<<endl;
}
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
    cout<<"Successfully inserted at end!"<<endl<<endl;
}
void insert_at_position(Node *&head, int pos, int val){
    // create head node 
    Node *newNode = new Node(val);
    if(head == NULL && pos == 1){
        head = newNode;
    }
    else{
        Node *tmp = head;
        for(int i=1;i<pos-1;i++){
            // traverse 
            tmp = tmp->next;
        }
        // first connect next nodes to the next of newNode 
        newNode->next = tmp->next;
        // now connect newNode after tmp 
        tmp->next = newNode;
    }
    cout<<"Successfully inserted at "<<pos<<" position!"<<endl;
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
    // create head node initially as null pointer 
    Node *head = NULL;
    while(1){
        cout<<"Enter 1 for insert node at begining"<<endl;
        cout<<"Enter 2 for insert node at end"<<endl;
        cout<<"Enter 3 for insert node at middle"<<endl;
        cout<<"Enter 4 to print the linked list"<<endl;
        cout<<"Enter 5 to delete any node"<<endl;
        cout<<"Enter 6 to delete head node"<<endl;
        cout<<"Enter 7 to delete last node"<<endl;
        cout<<"Enter 8 to exit"<<endl<<endl;
        cout<<"Enter your choice: ";
        int ch;
        cin>>ch;
        cout<<endl;
        bool flag = 0;
        switch (ch){
            case 1:
                int num;
                cout<<"Enter the value of node: "<<endl;
                cin>>num;
                insert_at_beginning(head,num);
                break;
            case 2:
                int value;
                cout<<"Enter the value of node: "<<endl;
                cin>>value;
                insert_at_end(head,value);
                break;
            case 3:
                int num1, pos;
                int nodeCount;
                nodeCount = node_count(head)+1;
                do{
                    cout<<"Please enter a position between 1 to "<<nodeCount<<" : "<<endl;
                    cin>>pos;
                }while(pos<1 || pos>nodeCount+1);
                cout<<"Enter the value of node: "<<endl;
                cin>>num1;
                insert_at_position(head, pos, num1);
                break;
            case 4:
                print_linked_list(head);
                break;
            case 5:
                int indx;
                int totalNode;
                totalNode = node_count(head);
                if(totalNode == 0){
                    cout<<"Sorry! there is no node to delete!"<<endl;
                }
                else{
                    do{
                        cout<<"Please enter a position between 1 to "<<totalNode<<" : "<<endl;
                        cin>>indx;
                    }while(indx<1 || indx>totalNode+1);
                    delete_node(head,indx);
                }
                break;
            case 6:
                delete_head_node(head);
                break;
            case 7:
                delete_last_node(head);
                break;
            case 8:
                flag = 1;
                break;
            default:
                break;
        }
        if(flag){
            cout<<"Successfully exited from the program"<<endl;
            break;
        }
    }
    return 0;
}
