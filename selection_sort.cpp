// ---------------Selection Sort--------- 
#include<bits/stdc++.h>
using namespace std;
int main(){
    // number of element in an array
    int n;
    cin>>n;
    int arr[n];
    // take array input 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // sort array in ascending order using selection sort technique 
    for(int i=0;i<n-1;i++){
        // find the minimum element from the array 
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        // if minimum element is found then swap with the current element 
        if(minIndex != i){
            swap(arr[i], arr[minIndex]);
        }
    }
    // print array after being sorted 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
