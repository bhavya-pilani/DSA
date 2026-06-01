#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005; // Note: N is up to 10^5 for this problem
vector<int> adj[MAXN];

int maxDist = -1;
int farthestNode = 0;

int dist1[MAXN];
int dist2[MAXN];

// Bug-proof DFS: passing the target array by reference
void dfs(int node, int p, int d, int distArray[]) {
    distArray[node] = d;
    if (d > maxDist) {
        maxDist = d;
        farthestNode = node;
    }

    for (int child : adj[node]) {
        if (child != p) {
            dfs(child, node, d + 1, distArray);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1st Pass: Find first diameter endpoint (f1)
    maxDist = -1;
    dfs(1, 0, 0, dist1);
    int f1 = farthestNode;

    // 2nd Pass: Find second endpoint (f2) and record distances from f1
    maxDist = -1;
    dfs(f1, 0, 0, dist1);
    int f2 = farthestNode;
    
    // The diameter of the tree is the max distance found in the 2nd pass
    int D = maxDist; 

    // 3rd Pass: Record distances from f2
    maxDist = -1;
    dfs(f2, 0, 0, dist2);

    // Frequency array to count how many nodes have a specific max_dist
    vector<int> count_at_dist(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int maximum_distance = max(dist1[i], dist2[i]);
        count_at_dist[maximum_distance]++;
    }

    // Prefix sum to quickly find how many nodes have max_dist < k
    vector<int> isolated_nodes(n + 1, 0);
    int current_isolated = 0;
    for (int k = 1; k <= n; k++) {
        isolated_nodes[k] = current_isolated;
        current_isolated += count_at_dist[k]; 
    }

    // Output the answer for each k
    for (int k = 1; k <= n; k++) {
        if (k > D) {
            // k is strictly greater than the tree's diameter
            cout << n << " ";
        } else {
            // C isolated nodes + 1 giant component
            cout << isolated_nodes[k] + 1 << " ";
        }
    }
    cout << "\n";

    return 0;
}