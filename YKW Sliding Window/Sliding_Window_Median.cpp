#include <bits/stdc++.h>
using namespace std;
using ll = long long;

multiset<int>low;
multiset<int>high;

void balance(){
    while (low.size() > high.size() + 1) {
        auto largest_in_low = prev(low.end());
        high.insert(*largest_in_low);
        low.erase(largest_in_low);
    }
    // If 'high' has more elements than 'low', move the smallest one to 'low'
    while (high.size() > low.size()) {
        auto smallest_in_high = high.begin();
        low.insert(*smallest_in_high);
        high.erase(smallest_in_high);
    }
}

void addElement(int x){
    if(low.empty() || x<=*low.rbegin()){
        low.insert(x);
    }
    else high.insert(x);

    balance();
}

void removeElement(int x){
    auto it = high.find(x);
    if (it != high.end()) {
        high.erase(it);
    } else {
        it = low.find(x);
        low.erase(it);
    }
    balance();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0;i<k;i++){
        addElement(arr[i]);
    }

    cout<<*low.rbegin()<<" ";

    for(int i=k;i<n;i++){
        addElement(arr[i]);
        removeElement(arr[i-k]);

        cout<<*low.rbegin()<<" ";
    }
    cout<<"\n";

    return 0;
}