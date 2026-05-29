#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll n,k;
    cin>>n>>k;
    
    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll>v(n);
    v[0]=x;


    for(int i=1;i<n;i++){
        v[i] = (a*v[i-1] + b) % c;
    }

    ll ans=0,curr=0;

    for(int i = 0; i < n; i++){
        
        if(i>=k){
            ans=ans^curr;
            curr=curr^v[i-k];
        }

        curr=curr^v[i];
    }
    ans ^= curr; 

    cout<<ans<<endl;

    return 0;
}