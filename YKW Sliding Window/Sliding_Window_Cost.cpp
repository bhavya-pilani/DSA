#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

multiset<int> low;
multiset<int> high;
ll sum_low = 0;
ll sum_high = 0;

void balance() {
    // If low gets too big, move largest to high
    while (low.size() > high.size() + 1) {
        auto it = prev(low.end());
        int val = *it;
        
        high.insert(val);
        sum_high += val;
        
        sum_low -= val;
        low.erase(it);
    }
    // If high gets too big, move smallest to low
    while (high.size() > low.size()) {
        auto it = high.begin();
        int val = *it;
        
        low.insert(val);
        sum_low += val;
        
        sum_high -= val;
        high.erase(it);
    }
}

void add_element(int x) {
    if (low.empty() || x <= *low.rbegin()) {
        low.insert(x);
        sum_low += x;
    } else {
        high.insert(x);
        sum_high += x;
    }
    balance();
}

void remove_element(int x) {
    auto it = high.find(x);
    if (it != high.end()) {
        sum_high -= x;
        high.erase(it);
    } else {
        it = low.find(x);
        sum_low -= x;
        low.erase(it);
    }
    balance();
}

// O(1) calculation of the absolute differences using sums
ll get_cost() {
    ll median = *low.rbegin();
    ll size_low = low.size();
    ll size_high = high.size();
    
    ll cost_low = (size_low * median) - sum_low;
    ll cost_high = sum_high - (size_high * median);
    
    return cost_low + cost_high;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 1. Process initial window
    for (int i = 0; i < k; i++) {
        add_element(arr[i]);
    }
    
    cout << get_cost();

    // 2. Slide the window
    for (int i = k; i < n; i++) {
        remove_element(arr[i - k]);
        add_element(arr[i]);
        
        cout << " " << get_cost();
    }
    
    cout << "\n";

    return 0;
}