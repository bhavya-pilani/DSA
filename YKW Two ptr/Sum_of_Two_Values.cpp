#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }

    sort(a.begin(), a.end());

    int l = 0;
    int r = n - 1;

    while (l < r) {
        long long current_sum = (long long)a[l].first + a[r].first;

        if (current_sum == x) {
            cout << a[l].second << " " << a[r].second << "\n";
            return 0;
        } 
        else if (current_sum < x) {
            l++; // Need a larger sum
        } 
        else {
            r--; // Need a smaller sum
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}