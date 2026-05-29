#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n,q;
    cin>>n>>q;

    vector<int>pre(n+1,0);

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        pre[i]=pre[i-1]^x;
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        cout<<(pre[r]^pre[l-1])<<endl;
    }
    

    return 0;
}