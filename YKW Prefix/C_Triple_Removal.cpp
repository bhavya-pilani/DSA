#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
    int n,q;
    cin>>n>>q;

    vector<int>pre1(n+1,0),a(n+1),preAdj(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre1[i]=pre1[i-1]+a[i];
    }

    for(int i=1;i<n;i++){
        preAdj[i]=preAdj[i-1] + (a[i]==a[i+1] ? 1 : 0);    // preAdj[i] is 
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        int cnt1 = pre1[r]-pre1[l-1];

        int cnt0 = r-l+1 - cnt1;

        if(cnt1%3!=0 || cnt0%3!=0){
            cout<<-1<<endl;
        }

        else{
            if(preAdj[r-1]-preAdj[l-1] == 0){
                cout<<((r-l+1)/3 + 1)<<endl;
            }
            else cout<< (r-l+1)/3<<endl;
        }

        
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