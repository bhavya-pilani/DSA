#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
char mv[] = {'D','U','R','L'};

int main() {
    int n,m;
    cin>>n>>m;

    vector<string>grid(n);

    for(int i = 0; i < n; i++){
        cin>>grid[i];
    }

    queue<pair<int,int>> q;

    vector<vector<int>> monster(n, vector<int>(m,1e9));

    vector<vector<int>> dist(n, vector<int>(m,-1));

    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));

    vector<vector<char>> move_dir(n,vector<char>(m));

    pair<int,int> start;

    // push all monsters
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M'){
                q.push({i,j});
                monster[i][j]=0;
            }
            if(grid[i][j]=='A')
                start={i,j};
        }
    }

    while(!q.empty()){
        auto [r,c]=q.front(); q.pop();

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m
               && grid[nr][nc]!='#'
               && monster[nr][nc]==1e9){

                monster[nr][nc]=monster[r][c]+1;
                q.push({nr,nc});
            }
        }
    }


    // PLAYER BFS
    queue<pair<int,int>> pq;
    pq.push(start);
    dist[start.first][start.second]=0;

    while(!pq.empty()){
        auto [r,c]=pq.front(); pq.pop();

        // boundary escape
        if(r==0 || c==0 || r==n-1 || c==m-1){

            string path="";
            pair<int,int> cur={r,c};

            while(cur!=start){
                path+=move_dir[cur.first][cur.second];
                cur=parent[cur.first][cur.second];
            }

            reverse(path.begin(),path.end());

            cout<<"YES\n";
            cout<<path.size()<<"\n";
            cout<<path<<"\n";
            return 0;
        }

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m
               && grid[nr][nc]!='#'
               && dist[nr][nc]==-1){

                int nextTime = dist[r][c]+1;

                // monster safety check
                if(nextTime < monster[nr][nc]){
                    dist[nr][nc]=nextTime;
                    parent[nr][nc]={r,c};
                    move_dir[nr][nc]=mv[i];
                    pq.push({nr,nc});
                }
            }
        }
    }

    cout<<"NO\n";
    

    return 0;
}