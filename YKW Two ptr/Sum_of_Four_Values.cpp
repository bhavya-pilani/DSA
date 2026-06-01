#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Map stores {pair_sum -> {original_index_1, original_index_2}}
    // We use std::map to avoid worst-case hash collisions that can occur in unordered_map on CSES
    map<long long, pair<int, int>> pair_sums;

    for (int i = 0; i < n; ++i) {
        
        // 1. LOOK FORWARD: Try to form the target with the current element and any element after it
        for (int j = i + 1; j < n; ++j) {
            long long current_pair_sum = (long long)a[i] + a[j];
            long long needed_sum = x - current_pair_sum;

            // If the needed sum exists in our map, we found our 4 distinct indices
            if (pair_sums.count(needed_sum)) {
                // Add 1 to all indices because CSES requires 1-based output
                cout << pair_sums[needed_sum].first + 1 << " " 
                     << pair_sums[needed_sum].second + 1 << " " 
                     << i + 1 << " " 
                     << j + 1 << "\n";
                return 0;
            }
        }

        // 2. LOOK BACKWARD: Add pairs ending at 'i' to the map
        // Doing this AFTER the forward check perfectly isolates the indices
        for (int j = 0; j < i; ++j) {
            pair_sums[(long long)a[j] + a[i]] = {j, i};
        }
    }

    // If the loop finishes without returning, no quadruplet exists
    cout << "IMPOSSIBLE\n";

    return 0;
}