#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> adj(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<vector<ll>> dist(n+1, vector<ll>(2, INF));

    priority_queue<tuple<ll,int,int>,
        vector<tuple<ll,int,int>>,
        greater<>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0}); // {cost, node, used}

    while(!pq.empty()){
        auto [cost, node, used] = pq.top();
        pq.pop();

        if(cost > dist[node][used]) continue;

        for(auto [nbr, w] : adj[node]){

            // case 1: no discount
            if(dist[nbr][used] > cost + w){
                dist[nbr][used] = cost + w;
                pq.push({dist[nbr][used], nbr, used});
            }

            // case 2: use discount
            if(used == 0){
                if(dist[nbr][1] > cost + w/2){
                    dist[nbr][1] = cost + w/2;
                    pq.push({dist[nbr][1], nbr, 1});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";

    return 0;
}