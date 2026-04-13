#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> rev(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;

        edges.push_back({u, v, -w}); // negate
        rev[v].push_back(u);         // reverse graph
    }

    vector<ll> dist(n+1, INF);
    dist[1] = 0;

    // Bellman-Ford
    for(int i = 1; i <= n-1; i++){
        for(auto e : edges){
            if(dist[e.u] < INF){
                dist[e.v] = min(dist[e.v], dist[e.u] + e.w);
            }
        }
    }

    // Find nodes that can reach n
    vector<bool> canReach(n+1, false);
    queue<int> q;
    q.push(n);
    canReach[n] = true;

    while(!q.empty()){
        int node = q.front(); q.pop();

        for(auto prev : rev[node]){
            if(!canReach[prev]){
                canReach[prev] = true;
                q.push(prev);
            }
        }
    }

    // Check negative cycle
    for(auto e : edges){
        if(dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w){
            if(canReach[e.v]){
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << -dist[n] << "\n"; // reverse back

    return 0;
}