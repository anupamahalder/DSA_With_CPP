#include<bits/stdc++.h>
using namespace std;
int facto(int n){
    if(n==0 || n==1) return 1;
    return n*facto(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<facto(n);
    return 0;
}
