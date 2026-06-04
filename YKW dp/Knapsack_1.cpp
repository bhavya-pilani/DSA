#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,W;
    cin>>n>>W;

    vector<ll>weights(n);
    vector<ll>value(n);

    for(int i=0;i<n;i++){
        cin>>weights[i];
        cin>>value[i];
    }

    // vector<vector<ll>>dp(n+1,vector<ll>(W+1,0));

    // for(int i=1;i<=n;i++){
    //     for(int w=1;w<=W;w++){
    //         dp[i][w] = dp[i-1][w]; // don't take

    //         if(weights[i-1] <= w){
    //             dp[i][w] = max( dp[i][w] , value[i-1] + dp[i-1][w-weights[i-1]]);
    //         }
    //     }
    // }
    // cout<<dp[n][W]<<"\n";

    vector<ll>dpp(W+1,0);
    vector<ll>dpc(W+1,0);

    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            dpc[w] = dpp[w]; // don't take

            if(weights[i-1] <= w){
                dpc[w] = max( dpc[w] , value[i-1] + dpp[w-weights[i-1]]);
            }
        }
        dpp=dpc;
    }
    cout<<dpc[W]<<"\n";




    return 0;
}