#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // dp[w][x] is true if we can form total sum 'w'
    // such that a subset of those coins sums to 'x'
    vector<vector<bool>> dp(k + 1, vector<bool>(k + 1, false));
    
    // Base case
    dp[0][0] = true;

    // Process each coin exactly once (0/1 Knapsack)
    for (int c : coins) {
        
        // Loop backwards for the outer sum to prevent reusing the coin
        for (int w = k; w >= c; w--) {
            
            // Loop backwards for the inner sum
            // Optimization: The inner sum 'x' can never exceed the outer sum 'w'
            for (int x = w; x >= 0; x--) {
                
                // Option 1 is implicitly handled because if dp[w][x] is already true, 
                // it remains true. We only need to check Options 2 and 3.

                // Option 2: Include in outer sum, but NOT inner sum
                if (dp[w - c][x]) {
                    dp[w][x] = true;
                }
                
                // Option 3: Include in BOTH outer sum AND inner sum
                if (x >= c && dp[w - c][x - c]) {
                    dp[w][x] = true;
                }
            }
        }
    }

    // Collect all valid inner sums 'x' when the outer sum is exactly 'k'
    vector<int> result;
    for (int x = 0; x <= k; x++) {
        if (dp[k][x]) {
            result.push_back(x);
        }
    }

    // Print the output strictly formatted as requested
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}