#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>>adj;
vector<int>vis;


void dfs(int src){
    vis[src]=1;

    for(auto nbr:adj[src]){
        if(!vis[nbr]) dfs(nbr);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;


    vis.resize(n+1,0);
    adj.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;

        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0;

    vector<int>sources;


    for(int i=1;i<=n;i++){
        if(!vis[i]){
            sources.push_back(i);
            ans++;
            dfs(i);
        }
    }

    cout<<ans-1<<endl;

    for(int i=0;i<ans-1;i++){
        cout<<sources[i]<<" "<<sources[i+1]<<"\n";
    }
    


    return 0;
}