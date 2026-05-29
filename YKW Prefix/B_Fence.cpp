
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n,k;
    cin>>n>>k;

    vector<int>pre(n+1,0);

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        pre[i]=pre[i-1]+x;

    
    }
    int mini=INT_MAX;
    int idx=-1;

    for(int i=0;i<=n-k;i++){
        if(pre[i+k]-pre[i]<mini){
            mini=pre[i+k]-pre[i];
            idx=i;
        }

    }
    cout<<idx+1<<endl;

    

    return 0;
}