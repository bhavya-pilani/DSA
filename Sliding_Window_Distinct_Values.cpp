#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Fast I/O is essential for large n
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // std::map keeps the memory footprint small and handles the 10^9 values easily.
    map<int, int> freq;

    // 1. Process the initial window of size k
    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }
    
    // The size of the map is the number of distinct elements
    cout << freq.size();

    // 2. Slide the window across the rest of the array
    for (int i = k; i < n; i++) {
        // Element entering the window on the right
        freq[arr[i]]++;

        // Element leaving the window on the left
        int left_val = arr[i - k];
        freq[left_val]--;

        // Crucial: If a value's frequency drops to 0, it is no longer in the window.
        // Erase it so freq.size() remains accurate.
        if (freq[left_val] == 0) {
            freq.erase(left_val);
        }

        cout << " " << freq.size();
    }
    
    cout << "\n";

    return 0;
}