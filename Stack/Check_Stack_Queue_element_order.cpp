/*
Take a stack of size N and a queue of size M as input. 
Then check if both of them are the same or not in the order of removing. 
You should use STL to solve this problem.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    queue<int> qu;
    // take stack size of n
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        // taking input to stack 
        int x;
        cin>>x;
        st.push(x);
    }
    // take queue size of m
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        // taking input to queue 
        int x;
        cin>>x;
        qu.push(x);
    }
    bool flag = true;
    // check both stack and queue contains the same output or not 
    if(n!=m) cout<<"Not same!\n";
    else{
        while(!st.empty() && !qu.empty()){
            int s1 = st.top();
            st.pop();
            int q1 = qu.front();
            qu.pop();
            if(s1!=q1){
                flag = false;
                break;
            }
        }   
        if(flag) cout<<"Same!\n";
        else cout<<"Not Same!\n";
    }
    return 0;
}

/*
================OUTPUT SECTION===========
Input:
    5 
    1 2 3 4 5
    5
    1 2 3 4 5 
Output: Not same!
--------------------
Input:
    5 
    1 2 3 4 5
    5
    5 4 3 2 1 
Output: Same!
=========================================
*/
