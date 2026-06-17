#include<bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m){
    if(i<0 or i>=n or j<0 or j>=m) return 0;
    return 1;
}

int x[4]={-1,1,0,0};
int y[4]={0,0-1,1};

void dfs(vector<vector<char>>& a, int n, int m, int i, int j){
    a[i][j]='#';

    for(int k=0; k<4; k++){
        int row = i+x[k];
        int col = j+y[k];

        if(valid(row,col,n,m) and a[row][col]=='0') dfs(a,n,m,row,col);
    }
}

void solve(vector<vector<char>>& a){
    int n=a.size();
    int m=a[0].size();

    for(int j=0; j<m; j++){
        if(a[0][j]=='0') dfs(a,n,m,0,j);
    }
    for(int j=0; j<m; j++){
        if(a[n-1][j]=='0') dfs(a,n,m,n-1,j);
    }
    for(int i=0; i<n; i++){
        if(a[i][0]=='0') dfs(a,n,m,i,0);
    }
    for(int i=0; i<n; i++){
        if(a[i][m-1]=='0') dfs(a,n,m,i,m-1);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='#') a[i][j]='0';
            a[i][j]='x';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j];
        }
    }


}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> a(n);

    for(int i=0; i<n; i++){
        vector<char> temp;
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        a.push_back(temp);
    }


    solve(a);
return 0;
}