// You will be given an undirected graph as input. Then you will be given a node N. 
// You need to tell the number of nodes that can be visited from node N.

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1005];
bool vis[1005];

int nodeCount;

void dfs(int src){
    // make src as visited 
    vis[src] = true;
    nodeCount++;
    // get all children 
    for(int child: adj[src]){
        // check child is already visited or not 
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    while(edges--){
        int u,v;
        cin>>u>>v;
        // connected nodes in undirected both way 
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    // take a node as input 
    int srcNode;
    cin>>srcNode;
    // initalize nodeCount to 0
    nodeCount = 0;
    // call dfs
    dfs(srcNode);
    cout<<"The total number of nodes that can be visited from node "
    <<srcNode<<" is: "<<nodeCount<<endl;
    return 0;
}

/*
====================OUTPUT SECTION========================
Testcase 1:
------------
INPUT: 
      6 5
      0 1
      0 2
      0 3
      2 3
      4 5
      2
OUTPUT:
    The total number of nodes that can be visited from node 2 is: 4
---------------------------------------------
Testcase 2:
------------
INPUT: 
      6 5
      0 1
      0 2
      0 3
      2 3
      4 5
      4
OUTPUT:
    The total number of nodes that can be visited from node 4 is: 2
-----------------------------------------------
Testcase 3:
------------
INPUT:
      7 6
      0 1
      1 2
      2 3
      1 3
      4 0
      5 6
      1
OUTPUT:
      The total number of nodes that can be visited from node 1 is: 5
==========================================================
*/
