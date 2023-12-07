// ---------------String copy--------- 
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2,s3;
    cin>>s1;
    cout<<s1<<endl;

    // copy using index 
    for(int i=0;i<s1.size();i++){
        s2.push_back(s1[i]);
    }
    // s2 is now contains the copy of s1 string
    cout<<s2<<endl;
    
    // copy using '=' (assignment operator) 
    s3 = s1;
    // s3 is now contains the copy of s1 string
    cout<<s3<<endl;
    return 0;
}
