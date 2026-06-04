#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    vector<int>price(n),page(n),dp(x+1,0);

    for(int i = 0; i < n; i++){
        cin>>price[i];
    }
    for(int i = 0; i < n; i++){
        cin>>page[i];
    }

    dp[0]=0;

    // 1. OUTER LOOP: Books
    for(int j = 0; j < n; j++) {
        
        // 2. INNER LOOP: Capacity (going backwards)
        for(int i = x; i >= price[j]; i--) {
            
            dp[i] = max(dp[i], page[j] + dp[i - price[j]]);
            
        }
    }

    cout<<dp[x]<<"\n";
    

    return 0;
}