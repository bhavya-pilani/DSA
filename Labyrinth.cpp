#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"

vector<string> grid;
vector<vector<bool>> vis;
vector<vector<pii>> parent;
vector<vector<char>> move_dir;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
char dir[] = {'D','U','R','L'};

int main() {
    int n,m;
    cin>>n>>m;

    grid.resize(n);
    for(int i = 0; i < n; i++){
        cin>>grid[i];
    }

    vis.assign(n, vector<bool>(m,false));
    parent.assign(n, vector<pii>(m));
    move_dir.assign(n, vector<char>(m));

    pii src,dest;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j]=='A') src={i,j};
            if(grid[i][j]=='B') dest={i,j};
        }
    }

    queue<pii> q;
    q.push(src);
    vis[src.ff][src.ss] = true;

    bool found = false;

    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        if(r==dest.ff && c==dest.ss){
            found = true;
            break;
        }

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m 
               && !vis[nr][nc] 
               && grid[nr][nc] != '#'){

                vis[nr][nc]=1;
                parent[nr][nc] = {r,c};
                move_dir[nr][nc] = dir[i];
                q.push({nr,nc});
            }
        }
    }

    if(!found){
        no;
        return 0;
    }

    // reconstruct path
    string ans = "";
    pii cur = dest;

    while(cur != src){
        ans += move_dir[cur.ff][cur.ss];
        cur = parent[cur.ff][cur.ss];
    }

    reverse(ans.begin(), ans.end());

    yes;
    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";

    return 0;
}