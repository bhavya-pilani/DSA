#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    int x, a, b, c;
    cin>>x>>a>>b>>c;

    vector<ll>v(n);

    v[0]=x;

    for(int i=1;i<n;i++){
        v[i]=(a*v[i-1] +b) % c;
    }

    ll final_xor=0;

    deque<ll>dq;

    for(int i=0;i<n;i++){

        while(!dq.empty() && v[dq.back()]>=v[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(dq.front()<=i-k) dq.pop_front();

        if(i>=k-1){
            final_xor^=v[dq.front()];
        }
    }

    cout<<final_xor<<"\n";
    


    return 0;
}