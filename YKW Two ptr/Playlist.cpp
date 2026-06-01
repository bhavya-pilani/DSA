#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> current_songs;
    int l = 0;
    int max_len = 0;

    // Expand the window by moving the right pointer
    for (int r = 0; r < n; ++r) {
        
        // If the new song is already in our window, shrink from the left 
        // until the duplicate is completely removed.
        while (current_songs.count(a[r])) {
            current_songs.erase(a[l]);
            l++;
        }
        
        // Now it is guaranteed safe to add the new song
        current_songs.insert(a[r]);
        
        // Update the maximum length recorded so far
        max_len = max(max_len, r - l + 1);
    }

    cout << max_len << "\n";

    return 0;
}