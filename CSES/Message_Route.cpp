#include <bits/stdc++.h>
using namespace std;

#define pb push_back


int main() {
    int n,m;
    cin>>n>>m;

    bool found=0;

    vector<int>adj[n+1],vis(n+1,0),path,parent(n+1);

    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
        
    }

    queue<int>q;
    q.push(1);
    vis[1]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        if(node==n){
            found=1;
            break;
        }

        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                vis[nbr]=1;
                q.push(nbr);
                parent[nbr]=node;
            }
        }
    }

    if(!found) cout<<"IMPOSSIBLE"<<endl;

    

    else {
        int curr=n;

        while(parent[curr]!=1){
            path.pb(curr);
            curr=parent[curr];
        }
        
        path.pb(curr);
        path.pb(1);
        reverse(path.begin(),path.end());

        cout<<path.size()<<endl;
        for(int i:path) cout<<i<<" ";
        cout<<endl;
    }


    

    return 0;
}