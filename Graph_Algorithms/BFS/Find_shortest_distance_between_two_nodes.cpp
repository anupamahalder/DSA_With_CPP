//You will be given an undirected graph as input. 
// Then you will be given a query Q. For each query,
// you will be given source S and destination D. 
// You need to print the shortest distance between S and D. 
// If there is no path from S to D, print -1.

#include<bits/stdc++.h>
using namespace std;

//adjacency list
vector<int>adj[1005];
bool vis[1005];
int level[1005];

void bfs(int src, int des){
    // make src as visited array 
    vis[src] = true;
    queue<int>q;
    // push to queue 
    q.push(src);
    // set the src level as 0 
    level[src] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        // if we reach destination node then we can return from this function 
        if(parent == des) return;
        // get the child nodes 
        for(int child: adj[parent]){
            if(!vis[child]){
                // make child as visited 
                vis[child] = true;
                // push child into the queue 
                q.push(child);
                // set the level of child node plus one of the parent node 
                level[child] = level[parent] + 1;
            }
        }
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    // value of nodes will lie in the range b/w 0 to nodes-1 
    while(edges--){
        int u, v;
        cin>>u>>v;
        // undirected so both way connection b/w two nodes 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // // print the all nodes that connected to each node 
    // for(int i=0;i<nodes;i++){
    //     cout<<i<<" -> ";
    //     for(int node: adj[i]){
    //         cout<<node<<" ";
    //     }
    //     cout<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
        int src, des;
        cin>>src>>des;
        // find the destination b/w two nodes 
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        // call bfs for the src to reach dest with shortest destination
        bfs(src, des);
        // now check if destination node's level 
        cout<<"Shortest distance b/w "<<src<<" and "<<des<<" is: "<<level[des]<<endl;
    }
    return 0;
}

/*
====================OUTPUT SECTION===================================
Input: nodes = 6, edges = 8
       0 4
       2 3
       5 3
       0 2
       4 3
       2 5
       0 1
       1 3
       q = 4
       2 3
       4 5
       0 5
       1 3
Ouput:
  Shortest distance b/w 2 and 3 is: 1
  Shortest distance b/w 4 and 5 is: 2
  Shortest distance b/w 0 and 5 is: 2
  Shortest distance b/w 1 and 3 is: 1

======================================================================
*/
