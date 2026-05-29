#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,q;
    cin>>n>>q;

    vector<vector<int>>pre(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        string row;
        
        cin>>row;

        for(int j=1;j<=n;j++){
            
            int isTree = row[j-1]=='*' ? 1 : 0;

            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + isTree;
        }
    }


    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;

        int total_trees = pre[y2][x2] 
                        - pre[y1 - 1][x2] 
                        - pre[y2][x1 - 1] 
                        + pre[y1 - 1][x1 - 1];
                        
        cout << total_trees << "\n";


    }
    

    return 0;
}