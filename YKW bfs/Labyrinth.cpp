#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<string>grid(n);
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>>move(n,vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    int startX,startY,endX,endY;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                startX=i;
                startY=j;
            }
            if(grid[i][j]=='B'){
                endX=i;
                endY=j;
            }
        }
    }

    queue<pair<int,int>>q;
    q.push({startX,startY});
    visited[startX][startY]=1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] ={'U','D','L','R'};

    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();

        if(x==endX && y==endY) break;

        int nx,ny;

        for(int i=0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];

            if(nx<n && ny<m && nx>=0 && ny>=0 && grid[nx][ny]!='#' && !visited[nx][ny] ){
                q.push({nx,ny});
                visited[nx][ny]=1;

                parent[nx][ny] = {x,y};
                move[nx][ny] = dir[i];
            }
        }
    }

    if(!visited[endX][endY]){
        cout<<"NO\n";
        return 0;
    }

    string ans="";
    
    pair<int,int>curr={endX,endY};


    while(curr!=make_pair(startX,startY)){
        ans+=move[curr.first][curr.second];
        curr=parent[curr.first][curr.second];
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";

    cout << ans.length() << "\n";
    cout << ans << "\n";


    

    return 0;
}