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

    int INF = 1e9; 
    vector<int> dp(x + 1, INF);

    dp[0]=0;  // dp[i] = min coins needed to make sum i

    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            int c = coins[j]; 

            if(i-c>=0)
                dp[i] = min(dp[i] ,1 + dp[i-c]);

        }
    }

    if (dp[x] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[x] << "\n";
    }

    return 0;
}