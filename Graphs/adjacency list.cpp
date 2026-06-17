#include<bits/stdc++.h>
using namespace std;
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


    for(int i=0; i<n; i++){
        cout<<i<<": ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
4
5
0 1
0 2
1 2
1 3
2 3

output :

0: 1 2 
1: 0 2 3 
2: 0 1 3 
3: 1 2 
*/