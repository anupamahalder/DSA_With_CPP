// You will be given an undirected graph which will be connected as input. 
// Then you will be given a level L. You need to print the node values at 
// level L in descending order. The source will be 0 always.

#include<bits/stdc++.h>
using namespace std;

// declare an adjacency list 
vector<int>adj[1005];
bool vis[1005];
int level[1005];

void bfs(int src, int l, vector<int>&ans){
    // make src as visited 
    vis[src] = true;
    // set level of src as 0 
    level[src] = 0;
    queue<int>q;
    // push src to queue 
    q.push(src);
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        // if parent's level matches with the input level push that node to ans
        if(level[parent]==l){
            ans.emplace_back(parent);            
        }
        // get child of that node 
        for(int child: adj[parent]){
            if(!vis[child]){
                // make child as visited 
                vis[child] = true;
                // push child to queue 
                q.push(child);
                // set the level of child node 
                level[child] = level[parent] + 1;
            }
        }
    }
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    while(edges--){
        int u,v;
        cin>>u>>v;
        // undirected graph so both way connection is there b/w two nodes 
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int l;
    // take level as input 
    cin>>l;
    vector<int>ans;
    // initalize visited array and level array 
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    
    // call bfs by passing sorce as 0
    bfs(0,l, ans);
    // sort the ans array in descending order
    sort(ans.begin(),ans.end(), greater<int>());
    // print the array 
    cout<<"The nodes in the level "<<l<<" --> ";
    for(int num: ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}

/*
===================OUPUT SECTION==============================
Testcase 1:
-------------
  Input: 
        3 2
        0 1
        0 2
        1
  Output:
    The nodes in the level 1 --> 2 1
---------------------------------------------------
Testcase 2:
--------------
Input:
      6 7
      0 1
      0 2
      1 2
      0 3
      4 2
      3 5
      4 3
      1
Output:
    The nodes in the level 1 --> 3 2 1
--------------------------------------------------
Testcase 3:
------------
Input:
    6 7
    0 1
    0 2
    1 2
    0 3
    4 2
    3 5
    4 3
    2
Output:
    The nodes in the level 1 --> 5 4

===============================================================
*/
