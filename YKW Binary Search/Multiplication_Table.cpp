#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    // The binary search range
    ll low = 1;
    ll high = n * n;
    ll target = (n * n + 1) / 2;
    ll ans = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll count = 0;

        // Count how many numbers in the table are <= mid
        for (ll i = 1; i <= n; i++) {
            count += min(n, mid / i);
        }

        // If count is at least target, mid might be our answer, 
        // but we look for a smaller valid number to find the exact boundary.
        if (count >= target) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; // mid is too small, we haven't reached the median yet
        }
    }

    cout << ans << "\n";
    return 0;
}