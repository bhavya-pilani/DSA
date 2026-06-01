#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Since a_i <= 10^5, we can safely allocate a flat vector of size 10^5 + 1
    // This gives us guaranteed O(1) lookups with zero hash collision risk.
    vector<int> freq(100005, 0);
    
    int distinct_count = 0;
    ll total_segments = 0;
    
    int l = 0;

    for (int r = 0; r < n; ++r) {
        
        // If it's a completely new element in our current window
        if (freq[a[r]] == 0) {
            distinct_count++;
        }
        freq[a[r]]++;

        // If the window has too many unique elements, shrink it
        while (distinct_count > k) {
            freq[a[l]]--;
            
            // If we completely removed an element, our distinct count drops
            if (freq[a[l]] == 0) {
                distinct_count--;
            }
            l++;
        }

        // Add the number of valid subarrays ending at R
        total_segments += (r - l + 1);
    }

    cout << total_segments << "\n";

    return 0;
}