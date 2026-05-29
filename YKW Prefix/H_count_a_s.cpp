#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int q;
    cin >> q;

    int n = s.size();

    vector<int> pre(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];

        if (s[i - 1] == 'a')
            pre[i]++;
    }

    while (q--) {
        int L, R;
        cin >> L >> R;

        cout << pre[R] - pre[L - 1] << '\n';
    }

    return 0;
}