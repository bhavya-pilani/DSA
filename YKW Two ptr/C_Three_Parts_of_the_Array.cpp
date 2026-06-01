#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    int l = 0;
    int r = n - 1;
    
    long long sum1 = 0;
    long long sum3 = 0;
    long long max_valid_sum = 0;

    // Run until the pointers cross
    while (l <= r) {
        if (sum1 < sum3) {
            sum1 += d[l];
            l++;
        } 
        else if (sum1 > sum3) {
            sum3 += d[r];
            r--;
        } 
        else { // sum1 == sum3
            max_valid_sum = sum1;
            sum1 += d[l];
            l++;
        }
    }

    // Catch the final state in case they became equal on the exact step the pointers crossed
    if (sum1 == sum3) {
        max_valid_sum = max(max_valid_sum, sum1);
    }

    cout << max_valid_sum << "\n";

    return 0;
}