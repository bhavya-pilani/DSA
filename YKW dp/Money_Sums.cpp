#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>a(n);

    int maxi=0;
    
    for(int i = 0; i < n; i++){
        cin>>a[i];

        maxi+=a[i];
    }

    vector<int>dp(maxi+1,0);
    dp[0]=1;

    for(int coin:a){
        for(int i=maxi;i>=1;i--){
            if(i-coin>=0)
                if(dp[i-coin])
                    dp[i] = 1;

        }
    }

    vector<int> possible_sums;
    for (int j = 1; j <= maxi; j++) {
        if (dp[j]) {
            possible_sums.push_back(j);
        }
    }

    cout << possible_sums.size() << "\n";
    for (int i = 0; i < possible_sums.size(); i++) {
        cout << possible_sums[i] << (i == possible_sums.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}