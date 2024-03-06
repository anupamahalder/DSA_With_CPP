/*
You will be given an array A of size N. Print "YES" if there is any duplicate value in the array, "NO" otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    bool ans = false;
    // take input 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
        if(mp[x]>1) ans = true;
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

/*
======================OUTPUT SECTION===================
Input:
      5
      1 2 3 4 5
Output: NO
----------------------------------
Input: 6
      2 1 3 5 2 1 
Output: YES
=======================================================
*/
