#include <iostream>
#include <vector>

using namespace std;
using ll = long long; // Good habit to alias this

void solve() {
    int n, k;
    cin >> n >> k;

    // 1. Replaced unordered_map with vector. Size is n + 1, initialized to 0.
    vector<int> fr(n + 1, 0);
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        fr[a[i]]++;
    }

    vector<int> req(n + 1, 0);

    // Iterate up to n since a[i] <= n
    for (int i = 1; i <= n; ++i) {
        if (fr[i] == 0) continue; // Skip elements that aren't in the array
        
        if (fr[i] % k != 0) {
            cout << 0 << "\n";
            return;
        }
        req[i] = fr[i] / k;
    }

    int l = 0;
    
    // 2. Fixed Integer Overflow
    ll ans = 0; 

    // Replaced unordered_map with vector for the sliding window
    vector<int> cnt(n + 1, 0);

    for (int r = 0; r < n; r++) {
        cnt[a[r]]++;

        while (cnt[a[r]] > req[a[r]]) {
            cnt[a[l]]--;
            // Notice we no longer need to .erase() anything! 
            // A value of 0 in the vector is perfectly fine.
            l++;
        }
        ans += (r - l + 1);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}