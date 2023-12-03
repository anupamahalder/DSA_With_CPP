// ---------------binary search--------- 
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int arr_size, int target){
    int left = 0;
    int right = arr_size - 1;
    while(left <= right){
        //calculate the mid index value
        int mid = left + (right - left)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid+1;
        else right = mid-1;
    }
    // element is not present in array
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    // take array input 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // sort array 
    sort(arr, arr+n);
    int x;
    cin>>x;
    int res = binarySearch(arr,n,x);
    if(res == -1)
        cout<<"Element is not found!";
    else cout<<"Element is found!"<<endl;
    return 0;
}
