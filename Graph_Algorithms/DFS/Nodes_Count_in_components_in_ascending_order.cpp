// Question: You will be given an undirected graph as input. 
// You need to tell the number of nodes in each component in ascending order.

#include<bits/stdc++.h>
using namespace std;

// adjacency list 
vector<int>adj[1005];
bool vis[1005];
int countCompo;

// dfs function 
void dfs(int src){
    // make src as visited 
    vis[src] = true;
    // increment countCompo 
    countCompo++;
    // go to its child nodes 
    for(int node: adj[src]){
        if(!vis[node]){
            // call dfs 
            dfs(node);
        }
    }
}
int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    while(edges--){
        int u,v;
        cin>>u>>v;
        // undirected graph 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // initailize visited array to false 
    memset(vis, false, sizeof(vis));
    // find no of nodes in each component 
    vector<int>compo;
    // value of nodes will be in range of [0,n)
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
            countCompo = 0;
            // call dfs 
            dfs(i);
            // store value in the compo vector 
            compo.push_back(countCompo);
        }
    }
    // sort the compo vector 
    sort(compo.begin(),compo.end());
    // print the sorted vector of no of components in ascending order
    for(int num: compo){
        cout<<num<< " ";
    }
    cout<<endl;
    return 0;
}

/*
==========================OUTPUT SECTION===========================
Input:
      6 5
      0 1
      0 2
      0 3
      2 3
      4 5
Output: 2 4
--------------------------------
Input:
      9 7
      0 1
      0 2
      0 3
      2 3
      4 5
      6 8
      7 6
Output: 2 3 4
--------------------------------
Input:
      7 7
      0 1
      1 2
      2 3
      1 3
      4 0
      0 5
      5 6
Output: 7
--------------------------------
Input:
      10 5
      1 2
      2 3
      1 3
      4 0
      5 6
Output: 1 1 1 2 2 3 (Because 7 8 and 9 nodes are not connected, but they are also components)

===================================================================
*/
