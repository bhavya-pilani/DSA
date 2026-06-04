#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>>adj;
vector<int>present;

int valid_rest=0;
int n,m;

void dfs(int u,int parent,int consecutive){
    if(present[u]) consecutive++;
    else consecutive=0;

    if(consecutive>m) return;

    bool isLeaf=1;

    for(int child:adj[u]){
        if(parent!=child){
            isLeaf=0;
            dfs(child,u,consecutive);
        }
    }

    if(isLeaf) valid_rest++;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    present.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>> present[i];
    }

    adj.resize(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0);


    cout<<valid_rest<<"\n";



    


    return 0;
}