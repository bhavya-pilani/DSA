#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    ll n,q;
    cin>>n>>q;

    string s;
    cin>>s;

    vector<vector<ll>> pref(n + 1, vector<ll>(27, 0));

    vector<ll>fr(27,0);

    for(int i=1;i<=n;i++){
        char ch=s[i-1];
        fr[ch-'a']++;
        pref[i]=fr;

    }

    while(q--){
        ll l,r;
        char c;
        cin>>l>>r>>c;

        ll q=(l-1)/n;
        ll rem=(l-1)%n;

        ll lastEle = pref[n][c-'a'];
        // cout<<"la "<<lastEle<<" ";

        ll left = q*lastEle + pref[rem][c-'a'];
        
        q=r/n;
        rem=r%n;

        ll right = q*lastEle + pref[rem][c-'a'];

        cout<<right-left<<endl;

        
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