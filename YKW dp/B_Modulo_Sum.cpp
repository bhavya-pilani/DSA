#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // --- PHASE 1: The Math Shortcut ---
    if (n >= m) {
        cout << "YES\n";
        return 0;
    }

    // --- PHASE 2: Modulo Subset Sum DP ---
    // dp[j] is true if a subset sum with remainder 'j' modulo 'm' is possible
    vector<bool> dp(m, false);

    for (int i = 0; i < n; i++) {
        // We only care about the element's modulo
        int val = a[i] % m;
        
        // Use a temporary array to represent the state AFTER evaluating this element
        // We initialize it as a copy of dp (Option 1: Skip the element)
        vector<bool> next_dp = dp;

        // Option 2: Take the element entirely by itself
        next_dp[val] = true;

        // Option 3: Add the element to all previously reachable remainders
        for (int j = 0; j < m; j++) {
            if (dp[j]) {
                next_dp[(j + val) % m] = true;
            }
        }

        // Commit the changes for the next iteration
        dp = next_dp;

        // Early exit: If we hit a remainder of 0 at any point, we win!
        if (dp[0]) {
            cout << "YES\n";
            return 0;
        }
    }

    // If we finished the loop and dp[0] is still false
    cout << "NO\n";
    return 0;
}