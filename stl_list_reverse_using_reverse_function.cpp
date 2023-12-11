// Using STL list, take a doubly linked list as input and reverse it. After that print the linked list.
 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // declare doubly linked list in STL using list 
    list<int>list1(n);
    int num;
    // take input to the list
    for(int i=0;i<n;i++){
        cin>>num;
        list1.push_back(num);
    }
    // using reverse function reverse the list
    list1.reverse();
    // print the elements of the list 
    for(auto ele: list1){
        cout<<ele<<"  ";
    } 
    cout<<endl;
}
