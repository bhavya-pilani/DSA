#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int>color;

bool dfs(int node,int c){

    color[node]=c;

    int next_c= (c == 1) ? 2 : 1;

    for(auto nbr:adj[node]){
        if(color[nbr]==c) return 0;

        if(color[nbr]==0){
            if(dfs(nbr,next_c) == 0) return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

 
    adj.resize(n+1);
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    color.resize(n+1,0);

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            if (dfs(i, 1) == 0) {
                cout << "IMPOSSIBLE\n";
                return 0; 
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << color[i] << (i == n ? "" : " ");
    }
    cout << "\n";

 
    

    return 0;
}