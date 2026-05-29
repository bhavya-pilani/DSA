#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    string s;
    cin>>s;

    int q;
    cin>>q;

    int xor0 = 0;
    int xor1 = 0;

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            xor0 ^= a[i];
        }
        else xor1 ^= a[i];
    }

    vector<int>preXor(n+1,0);

    for(int i = 1; i <= n; i++){
        preXor[i]=preXor[i-1]^a[i-1];
    }


    while(q--){
        int ty;
        cin>>ty;

        if(ty==1){
            int l,r;
            cin>>l>>r;

            
            xor0 ^= preXor[r]^preXor[l-1];
            xor1 ^= preXor[r]^preXor[l-1];
            

        }
        else{
            int g;
            cin>>g;

            if(g==0) cout<<xor0<<" ";
            else cout<<xor1<<" ";

        }
    }
    cout<<endl;
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