#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n,q;
    cin>>n>>q;

    vector<vector<ll>>pref(1001,vector<ll>(1001,0));
    vector<vector<ll>>arr(1001,vector<ll>(1001,0));

    for(int i=0;i<n;i++){
        ll h,w;
        cin>>h>>w;
        arr[h][w]+=h*w;
    }

    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            
            pref[i][j]=pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + arr[i][j];
        }
    }

    while(q--){
        ll hs,ws,hb,wb;
        cin>>hs>>ws>>hb>>wb;

        ll ans = pref[hb-1][wb-1] - pref[hs][wb-1] - pref[hb-1][ws] + pref[hs][ws];

        cout<<ans<<endl;


    }


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}