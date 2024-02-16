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
    // print the total number of nodes connected to a node 
    cout<<"In node "<<node<<", total number of connected nodes: "<<adj[node].size()<<endl;
    return 0;
}

/*
======================OUTPUT SECTION=============================
Testcase 1:
-------------
INPUT: 
      6 5
      0 1
      0 2
      0 3
      2 3
      4 5
      2
OUTPUT:
     In node 2, total number of connected nodes: 2
----------------------------------------------
Testcase 2:
-------------
INPUT: 
     6 5
     0 1
     0 2
     0 3
     2 3
     4 5
     0
OUTPUT:
     In node 0, total number of connected nodes: 3
-----------------------------------------------
Testcase 3:
------------
INPUT:
      7 7
      0 1
      1 2
      2 3
      1 3
      4 0
      0 5
      5 6
      1
OUTPUT:
     In node 1, total number of connected nodes: 3
=================================================================
*/
