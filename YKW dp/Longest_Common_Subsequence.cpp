#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];

    // dp[i][j] = length of lcs using the first 'i' elements of a, and 'j' elements of b
    // The dimensions are already n+1 and m+1, so the 0th row/col are automatically 0!
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    // NO MANUAL BASE CASES NEEDED!

    // Start loops at 1 (meaning length 1)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            
            // Because 'i' is length, the actual array index is 'i-1'
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    // The answer is the bottom right cell: using all 'n' and 'm' elements
    cout<<dp[n][m]<<"\n";

    vector<int>ans;

    // Traceback starts at lengths n and m
    int i = n;
    int j = m;

    while(i > 0 && j > 0){
        // Again, look at the actual elements using -1
        if (a[i-1] == b[j-1]) {
            ans.push_back(a[i-1]);
            i--;
            j--;
        } else {
            if (dp[i-1][j] > dp[i][j-1]) {
                i--; 
            } else {
                j--; 
            }
        }
    }
    
    reverse(ans.begin(),ans.end());

    for (int k = 0; k < ans.size(); k++) {
        cout << ans[k] << (k == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}