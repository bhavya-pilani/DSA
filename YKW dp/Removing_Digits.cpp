#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Initialize DP array with a safe "Infinity" value
    int INF = 1e9;
    vector<int> dp(n + 1, INF);
    
    // Base case
    dp[0] = 0;

    // Fill the DP array from 1 to n
    for (int i = 1; i <= n; i++) {
        int temp = i;
        
        // Extract each digit from the current number 'i'
        while (temp > 0) {
            int digit = temp % 10;
            
            // We can only subtract non-zero digits
            if (digit > 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            
            temp /= 10;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}