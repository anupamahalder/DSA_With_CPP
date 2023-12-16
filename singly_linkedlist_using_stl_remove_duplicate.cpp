#include <bits/stdc++.h>

using namespace std;


void printList(forward_list<int>myList){
    for(auto it=myList.begin();it!=myList.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    // Write your code here
    forward_list<int>numList;
    int num;
    // Take input at head of the list 
    while(1){
        cin>>num;
        if(num==-1) break;
        numList.push_front(num);
    }
    // sort the list 
    numList.sort();
    // remove duplicates 
    numList.unique();
    //print the final sorted list
    printList(numList);
    return 0;
}
