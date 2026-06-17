#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>>& edges, int src){
    //create adjacency list:
    vector<vector<pair<int,int>>> a(n);
    for(int i=0; i<edges.size(); i++){
        vector<int> edge = edges[i];
        int s=edge[0];
        int d=edge[1];
        int w=edge[2];

        a[s].push_back({d,w});
        a[d].push_back({s,w});
    }


    // priority queue => min heap => {wt,node}
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>> > pq;
    
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();

        int d = p.first;
        int node = p.second;

        if(d > dist[node]) continue;

        for(auto x:a[node]){
            int neigh = x.first;
            int wt = x.second;

            if(d+wt < dist[neigh]){
                dist[neigh]=d+wt;
                pq.push({d+wt,neigh});
            }
        }
    }

    return dist;
}

int main(){
    int n,e;
    cout<<"Enter the number of nodes:\n";
    cin>>n;
    cout<<"Enter the number of edges:\n";
    cin>>e;

    vector<vector<int>> edges;
    for(int i=0; i<e; i++){
        vector<int> edge(3);
        cin>>edge[0]>>edge[1]>>edge[2];

        edges.push_back(edge);
    }

    vector<int> dist = dijkstra(n,edges,0);

    for(int i=0; i<n; i++){
        cout<<"Distance from 0 to "<<i<<" is: "<<dist[i]<<"\n";
    }

return 0;
}