// ---------------Print array in reverse order--------- 
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
    // print array in reverse order 
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    return 0;
}