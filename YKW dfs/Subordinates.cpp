#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> tree[200005];

vector<int>ans;

void dfs(int node){
    ans[node]=0;

    for(auto child:tree[node]){
        dfs(child);

        ans[node]+= (1+ans[child]);

    }



}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=2;i<=n;i++){
        int boss;
        cin>>boss;
        tree[boss].push_back(i);
    }

    ans.resize(n + 1);

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    

    return 0;
}