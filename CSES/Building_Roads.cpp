#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
bool vis[N];

void dfs(int node){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> reps;   // representatives of components

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            reps.push_back(i);
            dfs(i);
        }
    }

    cout << reps.size() - 1 << "\n";

    for(int i = 1; i < reps.size(); i++){
        cout << reps[i-1] << " " << reps[i] << "\n";
    }

    return 0;
}