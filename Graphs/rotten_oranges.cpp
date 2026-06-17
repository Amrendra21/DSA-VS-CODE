/*
You are a given a grid of n*m and each value is either (0,1,2).
    0=empty
    1=fresh orange
    2=rotten orange

every minute, each rotten orange will rot its neighbouring 4 fresh oranges (if any)

return the time taken to rotten the all the fresh oranges
if any fresh orange remains at the end -> return -1
*/


#include<bits/stdc++.h>
using namespace std;

int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};

bool valid(int i, int j, int n, int m){
    if(i<0 or i>=n or j<0 or j>=m) return 0;
    return 1;
}

int rotten(vector<vector<int>>& a){
    int n=a.size();
    int m=a[0].size();

    queue<pair<int,int>> q;
    int fresh=0;
    int time=0;

    // nested loop for counting no. of fresh oranges and pushing rotten into the queue
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==2){
                q.push({i,j});
                a[i][j]=-2;
            }
            else if(a[i][j]==1) fresh++;
        }
    }

    while(!q.empty() and fresh>0){
        time++;

        int s = q.size();
        while(s--){
            pair<int,int> p = q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            for(int k=0; k<4; k++){
                int row = r+x[k];
                int col = c+y[k];

                if(valid(row,col,n,m) and a[row][col]==1){
                    q.push({row,col});
                    a[row][col]=-2;
                    fresh--;
                }
            }
        }
    }

    if(fresh>0) return -1;
    return time;
}


int main(){
    cout<<"Enter the size of the grid:\n";
    int n,m;
    cin>>n>>m;

    cout<<"Enter the grid :\n";
    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    cout<<rotten(a)<<" ";
}

/*
Enter the size of the grid:
3 3
Enter the grid : 
2 1 1
1 1 0
0 1 1
4 
*/