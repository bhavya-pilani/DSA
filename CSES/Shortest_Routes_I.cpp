#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> adj(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<ll> dist(n+1, INF);
    dist[1] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        if(d > dist[node]) continue;

        for(auto [nbr, wt] : adj[node]){
            if(dist[node] + wt < dist[nbr]){
                dist[nbr] = dist[node] + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}