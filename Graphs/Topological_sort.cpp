#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<vector<int>>& edges){
    vector<int> ans;

    //--------------------------------------------
    vector<vector<int>> a(n);
    vector<int> indeg(n,0);
    for(int i=0; i<edges.size(); i++){
        vector<int> edge = edges[i];
        int src = edge[0];
        int dest = edge[1];
        a[src].push_back(dest);
        indeg[dest]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indeg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int x:a[node]){
            indeg[x]--;
            if(indeg[x]==0) q.push(x);
        }
    }
    //--------------------------------------------
    return ans;
}

int main(){
    int n,e;
    cout<<"Enter the number of nodes:\n";
    cin>>n;
    cout<<"Enter the number of edges:\n";
    cin>>e;

    vector<vector<int>> edges;
    for(int i=0; i<e; i++){
        vector<int> edge(2);
        cin>>edge[0]>>edge[1];

        edges.push_back(edge);
    }

    vector<int> result = solve(n,edges);

    if(result.size()!=n) cout<<"Graph contains a cycle! Topological Sort not possible.\n";
    else{
        cout<<"Topological sort: ";
        for(int x:result) cout<<x<<" ";
    }
}

/*

Enter the number of nodes:
4
Enter the number of edges:
5
0 1
0 3
1 2
3 1
3 2


Topological sort: 0 3 1 2 
*/