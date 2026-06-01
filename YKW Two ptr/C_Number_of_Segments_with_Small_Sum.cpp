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
    ll sum=0,ans=0;

    while(r<n){
        sum+=a[r];

        while(sum>s){
            sum-=a[l];
            l++;
        }
        ans+=r-l+1;
        r++;

    }
    cout<<ans<<"\n";

    return 0;
}