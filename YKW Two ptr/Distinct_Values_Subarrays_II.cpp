#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    ll l=0,ans=0;

    map<int,int>fr;

    for(int r=0;r<n;r++){

        fr[a[r]]++;

        while(fr.size()>k){
            fr[a[l]]--;
            if(fr[a[l]]==0) fr.erase(a[l]);
            l++;
        }

        ans+=r-l+1;

    }
    cout<<ans<<"\n";

    return 0;
}