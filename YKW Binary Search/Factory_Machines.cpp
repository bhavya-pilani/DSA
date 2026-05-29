#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a;
ll n,t;



bool check(ll m){
    ll totalProd=0;

    for(int i=0;i<n;i++){

        totalProd += m/a[i];
        if(totalProd >= t) return 1;
    }
    return 0;

}
int main() {
    cin>>n>>t;

    a.resize(n);

    for(auto &x : a) cin >> x;

    ll ans;

    ll l=1;
    ll h=a[0]*t; // any value , we have to take >=mini in arr, so any random will be greater than or equal to mini 

    while(l<=h){
        ll m = l + (h-l)/2;

        if(check(m)){
            ans=m;
            h=m-1;
        }
        else l=m+1;
    }

    cout<<ans<<endl;
    

    return 0;
}