#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>dp;

long long MOD = 1e9 + 7;


int solve(int i,int target){
    if(target == 0)
        return 1;

    if(i <= 0 || target<0)
        return 0;

    if(dp[i][target]!=-1) return dp[i][target];

    int ways = ( (solve(i-1,target-i))%MOD + solve(i-1,target)%MOD ) % MOD;

    return dp[i][target] = ways;
}

int solve2(int n,int t){

    dp[0][0]=1;
    
    for(int i=1;i<n;i++){
        for(int target=0;target<=t;target++){
            int ways = (target>=i) ? dp[i-1][target-i] : 0;
            ways += dp[i-1][target];

            dp[i][target] = ways % MOD;
        }
    }
    return dp[n-1][t];
}
int solve3(int n,int t){
    vector<int>prev(t+1,0);
    vector<int>curr(t+1,0);

    prev[0]=1;
    
    for(int i=1;i<n;i++){
        for(int target=0;target<=t;target++){
            int ways = (target>=i) ? prev[target-i] : 0;
            ways += prev[target];

            curr[target] = ways % MOD;
        }
        prev=curr;
    }
    return prev[t];
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long total_sum = n * (n + 1) / 2;

    // If the total sum is odd, we can't split it evenly
    if (total_sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long target = total_sum / 2;

    // dp[j] stores the number of ways to make sum j
    // vector<long long> dp(target + 1, 0);
    
    // // Base case: 1 way to make sum 0
    // dp[0] = 1;

    // // OUTER LOOP: The available numbers.
    // // CRITICAL: We only loop up to n - 1 to prevent double counting.
    // for (int i = 1; i < n; i++) {
        
    //     // INNER LOOP: The target sum.
    //     // CRITICAL: We loop BACKWARDS because each number can only be used once (0/1 Knapsack)
    //     for (int j = target; j >= i; j--) {
    //         dp[j] = (dp[j] + dp[j - i]) % MOD;
    //     }
    // }

    // cout << dp[target] << "\n";

    dp.resize(n,vector<int>(target+1,0));

    // cout<< solve(n-1,target)<<"\n";
    cout<< solve3(n,target)<<"\n";

    return 0;
}