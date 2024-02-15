// You will be given an undirected graph as input. Then you will be given a node N. 
// You need to print the number of nodes that are directly connected to the node N.
 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    // declare an adjacency list 
    vector<int>adj[nodes];
    while(edges--){
        int u,v;
        cin>>u>>v;
        // make connection in both ways 
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int node;
    cin>>node;
    int countNodes = 0;
    // count the total nodes connected to a node 
    for(int num: adj[node]){
        countNodes++;
    }
    // print the total number of nodes connected to a node 
    cout<<"In node "<<node<<", total number of nodes: "<<countNodes<<endl;
    return 0;
}
