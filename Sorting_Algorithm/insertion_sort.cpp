// Insertion sort

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    int i,j,item; //variables
    for(i=1;i<n;i++){
        //Assigning arr[i] into item
        item = arr[i];
        //Now we have to find the appropriate place for item
        j = i-1;
        while(j>=0 && arr[j]>item){
            //putting arr[j] into (j+1)th place
            arr[j+1] = arr[j];
            j = j-1;
        }
        //arr[j+1] is now the appropriate place for item 
        arr[j+1] = item;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //print the array before sorting
    cout<<"Before sorting the array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertion_sort(arr,n);
    //print the array after sorting
    cout<<"After sorting the array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
