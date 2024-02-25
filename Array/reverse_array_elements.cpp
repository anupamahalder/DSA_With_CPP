// ---------------Reverse array--------- 
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
    // reverse array 
    for(int i=0,j=n-1;i<j;i++,j--){
        // swap elements 
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    // print array elements 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
