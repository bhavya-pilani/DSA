#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int>missing;
    map<int,int>freq;

    for(int i=0;i<=k;i++){
        missing.insert(i);
    }

    for(int i=0;i<k;i++){
        if(arr[i]<k){

            freq[arr[i]]++;


            missing.erase(arr[i]);

        }
    }

    cout<<*missing.begin()<<" ";

    for(int i=k;i<n;i++){
        if(arr[i]<k){

            freq[arr[i]]++;
            missing.erase(arr[i]);
            
        }

        if(arr[i-k] < k) {
            freq[arr[i-k]]--;

            if(freq[arr[i-k]] == 0) {
                missing.insert(arr[i-k]);
            }
        }
        
        cout<<*missing.begin()<<" ";
    }

    cout<<"\n";

    
    

    return 0;
}