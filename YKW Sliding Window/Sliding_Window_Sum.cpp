#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O is a good habit, though input here is minimal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    if (!(cin >> n >> k)) return 0;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    // 1. Array Generation
    // Using a vector of size n to store the elements. 
    // Fits easily within the 512 MB limit.
    vector<long long> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    // 2. Initial Window Setup
    long long current_window_sum = 0;
    for (int i = 0; i < k; i++) {
        current_window_sum += arr[i];
    }

    // Initialize the answer with the first window's sum
    long long final_xor = current_window_sum;

    // 3. Sliding Window
    for (int i = k; i < n; i++) {
        // Subtract the element leaving the window, add the new element
        current_window_sum = current_window_sum - arr[i - k] + arr[i];
        
        // Accumulate the XOR
        final_xor ^= current_window_sum;
    }

    cout << final_xor << "\n";

    return 0;
}