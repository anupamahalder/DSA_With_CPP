// Print a string where word will be in reverse order

#include<bits/stdc++.h>
using namespace std;

void print_word_reverse(stringstream &ss){
    string word;
    if(ss>>word){
        print_word_reverse(ss);
        cout<<word<<" ";
    }
}
int main(){
    string s;
    //take input 
    getline(cin, s);
    stringstream ss(s);
    // calling function to print word in reverse order 
    print_word_reverse(ss);
    cout<<endl;
    return 0;
}
