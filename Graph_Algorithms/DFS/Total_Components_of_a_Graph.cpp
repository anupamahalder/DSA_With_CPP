// You will be given an undirected graph as input. 
// You need to tell the number of components in this graph.

#include<bits/stdc++.h>
using namespace std;
// adjacency list 
vector<int>adj[1005];
// visited array to track a node is visited or not 
bool vis[1005];

void dfs(int src){
    // make src as visited 
    vis[src] = true;
    // loop through the child nodes 
    for(int child: adj[src]){
        // if child node is not visited then call dfs 
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // initialize the visited array with false 
    memset(vis, false, sizeof(vis));
    // count the number of total components 
    int count = 0;
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
            // call dfs 
            dfs(i);
            // increment the value of count by 1 
            count++;
        }
    }
    cout<<"Number of total components: "<<count<<endl;
    return 0;
}

/*
====================OUTPUT SECTION==========================
INPUT: 
    nodes = 6, edges = 5
    0 1
    0 2
    0 3
    2 3
    4 5
OUTPUT: Number of total components: 2
----------------------------------------------------------
INPUT: 
    nodes = 9, edges = 7
    0 1
    0 2
    0 3
    2 3
    4 5
    6 8
    7 6
OUTPUT: Number of total components: 3
----------------------------------------------------------
INPUT: 
    nodes = 7, edges = 7
    0 1
    1 2
    2 3
    1 3
    4 0
    0 5
    5 6 
OUTPUT: Number of total components: 1
----------------------------------------------------------
INPUT: 
    nodes = 10, edges = 5
    1 2
    2 3
    1 3
    4 0
    5 6
      
OUTPUT: Number of total components: 6 
(Because 7 8 and 9 nodes are not connected, but they are also components)
----------------------------------------------------------
INPUT: 
      nodes = 8, edges = 6
      1 2 
      3 4
      6 4
      5 2
      8 7
      7 2
      
OUTPUT: Number of total components: 2

============================================================
*/
