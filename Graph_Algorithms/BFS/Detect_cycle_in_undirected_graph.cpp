// Detect cycle in undirected graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool vis[100005];
    int parentArray[100005];
    bool hasCycle;
    
    void bfs(int src, vector<int>adj[]){
        vis[src] = true;
        // push to queue 
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            // go to its child 
            for(int child: adj[parent]){
                if(vis[child] && parentArray[parent] != child){
                    hasCycle = true;
                }
                if(!vis[child]){
                    q.push(child);
                    vis[child] = true;
                    parentArray[child] = parent;
                }
            }
        }
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        memset(vis, false, sizeof(vis));
        memset(parentArray, -1, sizeof(parentArray));
        for(int i=0;i<V;i++){
            if(!vis[i]){
                hasCycle = false;
                bfs(i, adj);
                if(hasCycle) return true;
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
        // undirected so both way connection is required
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // call dfs 
    bool res = sol.isCycle(nodes, adj);
    // print cycle is found or not 
    if(res) cout<<"Cycle detected!"<<endl;
    else cout<<"No cycle found!"<<endl;
}

/*
=====================OUTPUT SECTION==============================
Input:
      4 2
      1 2
      3 2
Output: No cycle found!
----------------------------
Input:
      5 5
      0 1
      1 2
      1 4 
      3 2
      4 3
Output: Cycle detected!
=================================================================
*/
