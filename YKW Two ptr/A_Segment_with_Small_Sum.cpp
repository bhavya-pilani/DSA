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
    ll sum=0,maxL=0;

    while(r<n){
        sum+=a[r];

        if(sum>s){
            sum-=a[l];
            l++;
        }

        maxL=max(maxL,r-l+1);

        r++;

    }
    cout<<maxL<<"\n";

    return 0;
}