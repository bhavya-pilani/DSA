#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans=0;
    
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    vector<ll>pre(2*n+1,0);


    for(int i=1;i<=2*n;i++){
        pre[i]=pre[i-1] + a[(i-1)%n];
    }

    deque<int>dq;

    for(int i=1;i<2*n;i++){

        while(!dq.empty() && pre[dq.back()]>pre[i]) dq.pop_back();

        dq.push_back(i);

        while(!dq.empty() && dq.front()<=i-n) dq.pop_front();

        if(i>=n){
            if(pre[dq.front()] - pre[i-n]>=0) ans++;
        }
    }

    cout<<ans<<endl;


    return 0;
}