#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;


vector<int> adj[N];
bool vis[N];
int parent[N];

int st=-1,en=-1;

bool dfs(int src){
    vis[src]=1;

    for(auto nbr:adj[src]){
        if(vis[nbr]==1 && parent[src]!=nbr){
            //cycle
            st=nbr;
            en=src;
            return true;

        }
        else if(!vis[nbr]){
            parent[nbr]=src;
            if(dfs(nbr)) return true;
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i)){
                break;
            }
        }
    }

    if (st == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct cycle
    vector<int> cycle;
    cycle.push_back(st);

    int cur = en;

    while (cur != st) {
        cycle.push_back(cur);
        cur = parent[cur];
    }

    cycle.push_back(st);

    // reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (auto node : cycle)
        cout << node << " ";

    cout << "\n";

    return 0;


}