#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Edge Case: If start or end is a trap, a valid path is impossible
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        cout << 0 << "\n";
        return 0;
    }

    int MOD = 1e9 + 7;
    
    // dp matrix initialized to 0
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Base case: 1 way to start
    dp[0][0] = 1;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            
            // If it's a trap, the ways to reach here stay 0
            if (grid[r][c] == '*') {
                dp[r][c] = 0;
            } else {
                // Add paths from ABOVE (if not in the top row)
                if (r > 0) {
                    dp[r][c] = (dp[r][c] + dp[r - 1][c]) % MOD;
                }
                // Add paths from LEFT (if not in the first column)
                if (c > 0) {
                    dp[r][c] = (dp[r][c] + dp[r][c - 1]) % MOD;
                }
            }
        }
    }

    // The answer is the bottom-right cell
    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}