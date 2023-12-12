// Implementing stack using array
#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE=10;

class ArrStack{
    private:
        int stack[MAX_SIZE];
        int top;

    public:
        // constructor to initialize top
        ArrStack(){
            top = -1;
        }
        // methods for our ArrStack class
        // function to check stack is empty or not 
        bool isEmpty(){
            return top==-1;
        }
        // function to check stack is full or not 
        bool isFull(){
            return top==MAX_SIZE-1;
        }
        // function to insert element at top of the stack 
        void push(int val){
            if(isFull()){
                cout<<"Stack is overflow"<<endl;
                return;
            }
            stack[++top] = val;
        }
        // function to delete element at top of the stack
        void pop(){
            if(isEmpty()){
                cout<<"Stack is underflow"<<endl;
                return;
            }
            --top;
        }
        // function to get element at top of the stack
        int peek(){
            if(isEmpty()){
                cout<<"Stack is empty!"<<endl;
                // considering -1 will not be an element of the stack 
                return -1;
            }
            return stack[top];
        }
        void print_stack(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
            }
            else{
                for(int i=0;i<=top;i++){
                    cout<<stack[i]<<" ";
                }
                cout<<endl;
            }
        }
};
int main(){
    // create object of ArrStack class 
    ArrStack myStack;
    if(myStack.isEmpty()){
        cout<<"Stack is empty!"<<endl;
    }
    // push 5 elements 
    myStack.push(3);
    myStack.push(5);
    myStack.push(12);
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
