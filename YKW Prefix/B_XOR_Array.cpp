#include <iostream>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    int prev_p = 0;
    
    for (int i = 1; i <= n; ++i) {
        
        // If we reach index r, force the prefix XOR to duplicate prefix[l-1]
        // Otherwise, the prefix XOR is just the index i
        int curr_p = (i == r) ? (l - 1) : i;
        
        // The current array element is the XOR difference of the current and previous prefix
        cout << (curr_p ^ prev_p) << (i == n ? "" : " ");
        
        // Update the previous prefix for the next iteration
        prev_p = curr_p;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}