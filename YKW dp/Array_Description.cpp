#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int MOD = 1e9 + 7;

    // 2D DP table initialized to 0
    // dp[i][v] = ways to fill array up to index 'i' with value 'v'
    // Dimensions: n rows (indices 0 to n-1), m + 1 columns (values 1 to m)
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // --- BASE CASE (Index 0) ---
    if (x[0] == 0) {
        // If unknown, it could be any value from 1 to m
        for (int v = 1; v <= m; v++) {
            dp[0][v] = 1;
        }
    } else {
        // If known, there is only 1 way to be that specific value
        dp[0][x[0]] = 1;
    }

    // --- DP TRANSITIONS (Indices 1 to n-1) ---
    for (int i = 1; i < n; i++) {
        
        if (x[i] == 0) {
            // It's a wildcard. Calculate for all possible values v.
            for (int v = 1; v <= m; v++) {
                // Pull from v-1, v, and v+1 from the previous row (i-1)
                long long ways = dp[i - 1][v];
                if (v - 1 >= 1) ways += dp[i - 1][v - 1];
                if (v + 1 <= m) ways += dp[i - 1][v + 1];
                
                dp[i][v] = ways % MOD;
            }
        } else {
            // It's a fixed value. Only calculate for v = x[i].
            // All other columns in row 'i' remain 0.
            int v = x[i];
            
            long long ways = dp[i - 1][v];
            if (v - 1 >= 1) ways += dp[i - 1][v - 1];
            if (v + 1 <= m) ways += dp[i - 1][v + 1];
            
            dp[i][v] = ways % MOD;
        }
    }

    // --- FINAL RESULT ---
    // The total number of valid arrays is the sum of all valid 
    // values at the very last step (index n-1).
    long long total_ways = 0;
    for (int v = 1; v <= m; v++) {
        total_ways = (total_ways + dp[n - 1][v]) % MOD;
    }

    cout << total_ways << "\n";

    return 0;
}