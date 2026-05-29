#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll w, h, n;

bool check(ll X) {
    ll cols = X / w;
    ll rows = X / h;
    
    // If we can't even fit one rectangle in either dimension
    if (cols == 0 || rows == 0) return false;
    
    // Overflow protection: if rows or cols is already >= n, 
    // the product will definitely be >= n (since the other dimension is >= 1).
    if (cols >= n || rows >= n) return true;
    
    // Now it is mathematically safe to multiply. 
    // Since cols < n (10^9) and rows < n (10^9), cols * rows < 10^18.
    return cols * rows >= n;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> w >> h >> n;

    // Minimum possible square side length is 1
    ll low = 1; 
    
    // Maximum possible square is stacking all 'n' rectangles in the longest dimension
    ll high = max(w, h) * n; 
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;       // This square works, save it
            high = mid - 1;  // Try to find a smaller valid square
        } else {
            low = mid + 1;   // Square is too small, increase the size
        }
    }

    cout << ans << "\n";
    return 0;
}