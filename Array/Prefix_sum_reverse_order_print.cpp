/*
You will be given an integer array A of size N. You need to print the prefix sum array of the array A in reverse order.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // calculate prefix sum 
    for(int i=1;i<n;i++){
        a[i] += a[i-1];
    }
    // print the array in reverse order 
    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<" ";
    }
    return 0;
}

/*
====================OUTPUT SECTION============================
Input: 5
      2 4 1 5 3
Output:
      15 12 7 6 2 
---------------------------------------
Input: 3
      1000000000 1000000000 1000000000
Output:
      3000000000 2000000000 1000000000 
==============================================================
*/
