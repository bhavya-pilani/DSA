#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,s;
    cin>>n>>s;

    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    ll l=0,r=0;
    ll sum=0,minL=INT_MAX;

    while(r<n){
        sum+=a[r];

        while(sum>=s){
            minL=min(minL,r-l+1);
            sum-=a[l];
            l++;
        }


        r++;

    }
    if (minL == INT_MAX) {
        cout << -1 << "\n";
    } else {
        cout << minL << "\n";
    }

    return 0;
}