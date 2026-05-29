#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> v(n + 1);
    vector<long long> u(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        u[i] = v[i];
    }

    sort(u.begin() + 1, u.end());

    vector<long long> pref_v(n + 1, 0);
    vector<long long> pref_u(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        pref_v[i] = pref_v[i - 1] + v[i];
        pref_u[i] = pref_u[i - 1] + u[i];
    }

    int m;
    cin >> m;

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            cout << pref_v[r] - pref_v[l - 1] << "\n";
        } else if (type == 2) {
            cout << pref_u[r] - pref_u[l - 1] << "\n";
        }
    }

    return 0;
}