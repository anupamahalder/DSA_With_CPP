#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
        int data;
        Node *next;
    // constructor 
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
void insert_at_tail(Node *&head, Node *&tail, int val){
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
void delete_node(Node *&head){
    Node *tmp = head;
    while(tmp != NULL && tmp->next != NULL){
        int nodeval = tmp->data;
        Node *current = tmp;
        Node *nextnode = tmp->next;
        while(nextnode != NULL){
            if(nextnode->data == nodeval){
                current->next = nextnode->next;
                delete nextnode;
                nextnode = current->next;
            }
            else{
                current = nextnode;
                nextnode = nextnode->next;
            }
        }
        tmp = tmp->next;
    }
}

int main()
{
    // Write your code here
    Node *head = NULL;
    Node *tail = NULL;
    int num;
    while(1){
        cin>>num;
        if(num == -1) break;
        insert_at_tail(head, tail, num);
    }
    Node *tmp = head;
    delete_node(head);
    tmp = head;
    while(tmp != NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    return 0;
}
