#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(int x, map<int,int>&mp, set<pair<int,int>>&st){
    int fr=mp[x];

    if(fr>0){
        st.erase({-fr,x});

    }
    mp[x]++;
    fr++;
    st.insert({-fr,x});
    
}

void remove(int x, map<int,int>&mp, set<pair<int,int>>&st){
    int fr=mp[x];

    if(fr>1){
        st.erase({-fr,x});
        fr--;
        st.insert({-fr,x});
        mp[x]--;


    }
    else {
        st.erase({-fr,x});
        mp.erase(x);

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    
    vector<int> a(n);
    for(int i=0;i<n;i++){
       cin >> a[i];
    }

    map<int,int>mp;
    set<pair<int,int>>st;

    for(int i=0;i<k;i++){
        add(a[i],mp,st);

    }
    cout<<st.begin()->second;

    for(int i=k;i<n;i++){
        add(a[i],mp,st);
        remove(a[i-k],mp,st);

        cout<<" "<<st.begin()->second;

    }
    cout<<"\n";


    return 0;
}