#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<int,int>>>adj;
int cost1 = 0;

void dfs(int node,int parent){

    for(auto [nbr,wt]:adj[node]){

        if(nbr!=parent){
            cost1+=wt;
            if(nbr!=1) dfs(nbr,node);

            return;
        }

    }

}

void solve(){
    int n;
    cin>>n;

    adj.resize(n+1);

    int totalCost=0;

    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        totalCost+=w;

        adj[u].push_back({v,0});
        adj[v].push_back({u,w});
    }

    dfs(1,0);

    int cost2 = totalCost - cost1;

    cout << min(cost1, cost2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}