#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M=200005;
vector<int>adj[M];


int distA[M];
int distB[M];

void dfsA(int u, int p, int d) {
    distA[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfsA(v, u, d + 1);
        }
    }
}

void dfsB(int u, int p, int d) {
    distB[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfsB(v, u, d + 1);
        }
    }
}


void solve(){
    int n,x;
    cin>>n>>x;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    dfsA(1, 0, 0);

    dfsB(x, 0, 0);

    int max_moves = 0;

    for (int i = 1; i <= n; i++) {
        if (distB[i] < distA[i]) {
            max_moves = max(max_moves, 2 * distA[i]);
        }
    }

    cout << max_moves << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
        solve();
    
    return 0;
}