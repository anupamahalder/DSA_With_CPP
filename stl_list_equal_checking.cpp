// Create doubly linked list using STL list and check two lists are equal or not 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n; //n for size of first list
    // declare doubly linked list in STL using list 
    list<int>list1(n),list2(n);
    int num;
    // take input to first list
    for(int i=0;i<n;i++){
        cin>>num;
        list1.push_back(num);
    }
    cin>>m; //n for size of first list
    // take input to first list
    for(int i=0;i<m;i++){
        cin>>num;
        list2.push_back(num);
    }
    //checking two lists are equal or not 
    if(n==m){
        if(list1==list2) cout<<"Yes"<<endl;
        else cout<<"No, two lists are not equal!"<<endl;
    }
    else{
        cout<<"No, two lists are not equal!"<<endl;
    }
}
