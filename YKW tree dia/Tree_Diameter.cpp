#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
vector<int> adj[MAXN];

int maxDist=-1;
int farthestNode=0;

void dfs(int node,int p,int d){
    if(d>maxDist){
        maxDist=d;
        farthestNode=node;
    }

    for(int child:adj[node]){
        if(child!=p){
            dfs(child,node,d+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0);

    maxDist=-1;

    dfs(farthestNode,0,0);

    cout<<maxDist<<"\n";    

    return 0;
}