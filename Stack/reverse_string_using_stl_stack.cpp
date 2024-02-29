// Reverse a string using stack data structure
#include <iostream>
#include <stack>
using namespace std;

string reverseString(string s){
    stack<char>myStack;
    // pushing each character of string to stack 
    for(char ch: s){
        myStack.push(ch);
    }
    string revString;
    char c;
    // pop each character from stack until stack becomes empty 
    while(!myStack.empty()){
        c = myStack.top(); 
        revString.push_back(c);
        myStack.pop();
    }
    return revString;
} 

int main() {
    string str;
    getline(cin,str);
    str = reverseString(str);
    cout<<str<<endl;
    return 0;
}
