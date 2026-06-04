#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    if (!(cin >> n >> x)) return 0;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    int mod=1e9+7;
    vector<int> dp(x + 1, 0);

    dp[0]=1; // dp[i] = no. of ways to make sum i

    for(int c:coins){
        for(int i=1;i<=x;i++){

            if(i-c>=0)
                dp[i] = (dp[i] + dp[i-c]) % mod;
        }   
    }

    cout<<dp[x]<<"\n";


    return 0;
}