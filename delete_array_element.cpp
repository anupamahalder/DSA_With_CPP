// ---------------Delete array element--------- 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; // total no of elements
    cin>>n;
    int arr[n];
    // take array inputs 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos;
    cout<<"Enter a position to delete element:";
    cin>>pos;
    // index will be position-1 
    if(pos>0 && pos<n){
        for(int i=pos-1;i<n;i++){
            arr[i] = arr[i+1];
        }
        // update size of array 
        n--;
    }
    else{
        cout<<"Entered invalid position to delete element"<<endl;
    }
    cout<<"The array after delete element:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
