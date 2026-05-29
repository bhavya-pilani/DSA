#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n + 1);
    vector<long long> pref(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    
    long long total_sum = pref[n];
    
    for (int i = 0; i < q; ++i) {
        int l, r;
        long long k;
        cin >> l >> r >> k;
        
        long long replaced_sum = pref[r] - pref[l - 1];
        
        long long new_range_sum = k * (r - l + 1);
        
        long long current_sum = total_sum - replaced_sum + new_range_sum;
        
        if (current_sum&1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}