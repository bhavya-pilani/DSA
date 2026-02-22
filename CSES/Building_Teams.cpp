#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>color(n+1,0);

    for(int i = 1; i <= n; i++){
        if(color[i]!=0) continue;

        queue<int>q;
        q.push(i);
        color[i]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto nbr:adj[node]){
                if(color[nbr]==color[node]){
                    cout<<"IMPOSSIBLE"<<endl;
                    return 0;
                }
                if(color[nbr]==0){
                    color[nbr]= 3-color[node];
                    q.push(nbr);
                }
            }
        }

        
    }
    for(int i = 1; i <= n; i++)
        cout << color[i] << " ";

    cout << "\n";

    return 0;



}