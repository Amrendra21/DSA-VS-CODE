#include<bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m){
    if(i<0 or i>=n or j<0 or j>=m) return false;
    return true;
}

void dfs(vector<vector<char>>& a, int i, int j, int n, int m, vector<vector<bool>>& vis){
    vis[i][j]=1;
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    for(int k=0; k<4; k++){
        int row = i+x[k];
        int col = j+y[k];

        if(valid(row,col,n,m) and a[row][col]=='1' and vis[row][col]==false){
            dfs(a,row,col,n,m,vis);
        }
    }
}

int NoOfIslands(vector<vector<char>>& a){
    int n=a.size();
    int m=a[0].size();

    int res = 0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='1' and vis[i][j]==false){
                dfs(a,i,j,n,m,vis);
                res++;
            }
        }
    }

    return res;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> a(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    cout<<"There are "<<NoOfIslands(a)<<" islands"<<endl;
    return 0;
}

/*
9 6
0 0 1 0 0 0
0 1 0 0 0 0
0 0 1 1 1 0
0 0 1 1 1 0
0 0 0 0 0 0
1 1 0 0 0 0
0 0 1 1 0 0
0 1 0 0 1 1
0 0 0 0 0 0

output:
There are 7 islands
*/