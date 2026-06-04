#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    vector<int>height(n);

    for(int i = 0; i < n; i++){
        cin>>height[i];
    }

    int INF=1e9;
    
    vector<int>dp(n+1,INF);

    dp[1] = 0; // dp[i] is mini cost to reach stone i
    dp[2] = abs(height[1]-height[0]);

    for(int i=3;i<=n;i++){
        dp[i] = min( dp[i-1] + abs(height[i-1] - height[i-2]) , dp[i-2] + abs(height[i-1] - height[i-3]) );
    }

    cout<<dp[n]<<"\n";



    return 0;
}