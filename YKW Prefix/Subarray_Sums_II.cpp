#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,t;
    cin>>n>>t;

    map<ll,ll>mp;

    mp[0]=1;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    ll sum=0,ans=0;

    for(int i=0;i<n;i++){
        sum+=a[i];

        if(mp.find(sum-t)!=mp.end()) ans+=mp[sum-t];

        mp[sum]++;
    }
    cout<<ans<<endl;

    return 0;
}