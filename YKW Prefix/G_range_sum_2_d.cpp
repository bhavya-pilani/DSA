#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll x;
            cin >> x;

            pref[i][j] =
                pref[i - 1][j] +
                pref[i][j - 1] -
                pref[i - 1][j - 1] +
                x;
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll ans =
            pref[x2][y2]
            - pref[x1 - 1][y2]
            - pref[x2][y1 - 1]
            + pref[x1 - 1][y1 - 1];

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}