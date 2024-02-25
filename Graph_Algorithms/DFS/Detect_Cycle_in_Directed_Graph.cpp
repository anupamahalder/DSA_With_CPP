// Detect cycle in directed graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool vis[100005];
    bool pathVisit[100005];
    bool cycle;
    void dfs(int parent, vector<int>adj[]){
        // visit the parent 
        vis[parent] = true;
        // also path visit true 
        pathVisit[parent] = true;
        
        // go to child node 
        for(int child: adj[parent]){
            if(pathVisit[child]){
                cycle = true;
            }
            if(!vis[child]){
                dfs(child, adj);
            }
        }
        // backtrack 
        pathVisit[parent] = false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        memset(vis, false, sizeof(vis));
        memset(pathVisit, false, sizeof(pathVisit));
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cycle = false;
                dfs(i, adj);
                if(cycle) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    int nodes, edges;
    cin>>nodes>>edges;
    // declare an adjacency list 
    vector<int>adj[nodes];
    
    while(edges--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    // call dfs 
    bool res = sol.isCyclic(nodes, adj);
    // print cycle is found or not 
    if(res) cout<<"Cycle detected!"<<endl;
    else cout<<"No cycle found!"<<endl;
}

/*
====================OUTPUT SECTION=============================
Input:
      4 4
      0 1
      1 2
      2 3
      3 3
Output: Cycle detected!
----------------------------
Input: 
      3 2
      0 1
      1 2
Output: No cycle found!
    
===============================================================
*/
