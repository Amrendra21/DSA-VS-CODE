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

    // creating matrix :
    vector<vector<int>> adj(n,vector<int>(n,0));

    for(int i=0; i<e; i++){
        vector<int> edge = edges[i];
        int src = edge[0];
        int dest = edge[1];

        adj[src][dest]=1;
        adj[dest][src]=1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}

/*
4 
5
0 1
0 2
1 2
1 3
2 3

output: 

0 1 1 0 
1 0 1 1 
1 1 0 1 
0 1 1 0 
*/