// Stack implementation using linked list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
    // constructor 
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class LinkedlistStack{
    private:
        Node *top;

    public:
        // constructor to initialize the stack
        LinkedlistStack(){
            top = NULL;
        }
        // methods for our ArrStack class
        // function to check stack is empty or not 
        bool isEmpty(){
            return top==NULL;
        }
        // function to insert element at top of the stack 
        void push(int val){
            Node *newNode = new Node(val);
            newNode->next = top;
            top = newNode;
        }
        // function to delete element at top of the stack
        void pop(){
            if(top==NULL){
                cout<<"Stack underflow!"<<endl;
                return;
            }
            Node *deleteNode = top;
            top = top->next;
            delete deleteNode;
        }
        // function to get element at top of the stack
        int peek(){
            if(top==NULL){
                cout<<"Stack is empty!"<<endl;
                // considering -1 will not be an element of the stack 
                return -1;
            }
            return top->val;
        }
        void print_stack(){
            if(top==NULL){
                cout<<"Stack is empty"<<endl;
								return;
            }
            Node *tmp = top;
            while(tmp != NULL){
                cout<<tmp->val<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }
};
int main(){
    // create object of ArrStack class 
    LinkedlistStack myStack;
    if(myStack.isEmpty()){
        cout<<"Stack is empty!"<<endl;
    }
    // push 5 elements 
    myStack.push(3);
    myStack.push(5);
    myStack.push(12);
    myStack.push(8);
    myStack.push(7);
    myStack.push(9);
    
    // print the entire stack elements 
    myStack.print_stack(); // 3 5 12 7 9 

    // delete elements 
    myStack.pop();
    myStack.pop();

    // access the top element of the stack
    int topValue = myStack.peek(); // 12
    cout<<"The top of the stack element is: "<<topValue<<endl;

    return 0;
}
