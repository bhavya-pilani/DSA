#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string>grid;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;


void dfs(int x,int y){
    grid[x][y]='a';

    int nx,ny;
    for(int i=0;i<4;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='.'){
            dfs(nx,ny);
        }
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    grid.resize(n);

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                cnt++;
                dfs(i,j);
            }
        }
    }

    cout<<cnt<<"\n";

    return 0;
}