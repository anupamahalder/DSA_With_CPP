#include <iostream>
#include <stack>
using namespace std;

bool isValidParentheses(string s){
    stack<char>st;
    for(char ch: s){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            // if we encounter closing bracket which has no starting bracket 
            if(st.empty()) return false;
            char tp = st.top();
            st.pop();
            // now check with its matching bracket 
            if((ch==')' && tp!='(') ||(ch=='}' && tp!='{')||(ch==']' && tp!='[')){
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin,str);
    if(isValidParentheses(str)){
        cout<<"Yes, Valid Parentheses!"<<endl;
    }
    else{
        cout<<"Not Valid Parentheses!"<<endl;
    }
    return 0;
}
