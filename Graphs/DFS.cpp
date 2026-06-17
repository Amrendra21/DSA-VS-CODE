#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int node, vector<int>& result, vector<bool>& visited){
    result.push_back(node);
    visited[node]=1;

    // traverse its neighbours:
    for(int x:adj[node]){
        if(visited[x]==0) dfs(adj,x,result,visited);
    }
}

int main(){
    int n;
    cin>>n;

    int e;
    cin>>e;

    vector<vector<int>> edges;
    for(int i=0; i<e; i++){
        vector<int> edge(2);
        cin>>edge[0]>>edge[1];

        edges.push_back(edge);
    }


    // input is completed

    vector<vector<int>> adj(n);

    for(int i=0; i<e; i++){
        vector<int> edge = edges[i];
        int src = edge[0];
        int dest = edge[1];

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }


    cout<<endl<<"DFS traversal: ";
    vector<bool> visited(n,0);
    vector<int> result;

    dfs(adj,0,result,visited);

    for(int i=0; i<n; i++){
        cout<<result[i]<<" ";
    }
}

/*
5
4
0 2
0 3
0 1
2 4

DFS traversal: 0 2 4 3 1 
*/