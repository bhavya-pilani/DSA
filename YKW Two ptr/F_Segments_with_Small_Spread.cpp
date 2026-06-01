#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll k;
    if (!(cin >> n >> k)) return 0;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // A multiset to keep our window elements sorted
    multiset<ll> ms;
    
    int l = 0;
    ll total_segments = 0;

    for (int r = 0; r < n; ++r) {
        // Expand the window and let the multiset auto-sort the new element
        ms.insert(a[r]);

        // While the spread (Max - Min) is too large, shrink from the left
        while (*ms.rbegin() - *ms.begin() > k) {
            
            // CAUTION: Use .find() to erase ONLY ONE copy of the element
            ms.erase(ms.find(a[l]));
            l++;
        }

        // Add all valid subarrays ending at R
        total_segments += (r - l + 1);
    }

    cout << total_segments << "\n";

    return 0;
}