#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    
    vector<int>height(n);

    for(int i = 0; i < n; i++){
        cin>>height[i];
    }

    int INF=1e9;
    
    vector<int>dp(n,INF);

    dp[0] = 0; // dp[i] is mini cost to reach stone i+1

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){

            if(i-j>=0)
                dp[i] = min( dp[i] , dp[i-j] + abs(height[i] - height[i-j]) );
        }

    }

    cout<<dp[n-1]<<"\n";



    return 0;
}