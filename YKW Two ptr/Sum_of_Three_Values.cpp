#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    vector<pair<int,int>>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n-1;i++){
        int j=i+1;
        int k=n-1;

        while(j<k){
            if(a[i].first + a[k].first + a[j].first == x){
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<"\n";
                return 0;
            }

            if(a[i].first + a[k].first + a[j].first > x){
                k--;
            }
            else j++;

        }
    }
    cout<<"IMPOSSIBLE"<<"\n";


    

    return 0;
}