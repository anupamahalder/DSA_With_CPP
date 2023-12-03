// ---------------Bubble Sort--------- 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    // take array input 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // sort array in ascending order using bubble sort technique 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            // swap two elements
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    // print array after being sorted 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
