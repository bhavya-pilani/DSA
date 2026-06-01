#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
vector<int> adj[MAXN];

int maxDist=-1;
int farthestNode=0;



int f1,f2;

void dfs(int node,int p,int d,vector<int>&dist){
    dist[node]=d;
    if(d>maxDist){
        maxDist=d;
        farthestNode=node;
    }

    for(int child:adj[node]){
        if(child!=p){
            dfs(child,node,d+1,dist);
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

    vector<int>dist1(n+1);
    vector<int>dist2(n+1);

    dfs(1,0,0,dist1);

    f1=farthestNode;

    maxDist=-1;

    dfs(f1,0,0,dist1);

    f2=farthestNode;

    dfs(f2,0,0,dist2);

    for(int i=1;i<=n;i++){
        cout<<max(dist1[i],dist2[i])<<" ";
    }
    cout<<"\n";

    return 0;
}