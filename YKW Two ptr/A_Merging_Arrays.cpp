#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> b(m);
    for(auto &x : b) cin >> x;

    vector<int>ans;

    int i=0,j=0;

    while(i<n && j<m){
        if(a[i]<b[j]){
            ans.push_back(a[i++]);

        }
        else ans.push_back(b[j++]);
    }

    while(i<n) ans.push_back(a[i++]);

    while(j<m) ans.push_back(b[j++]);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";

    

    return 0;
}