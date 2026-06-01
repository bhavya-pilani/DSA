#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int color[MAXN];

int max_dist = -1;
int farthest_node = -1;

// Modified DFS: distance only increases when the color changes
void dfs(int node, int parent, int current_dist) {
    if (current_dist > max_dist) {
        max_dist = current_dist;
        farthest_node = node;
    }

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            // If colors are different, edge weight is 1. Otherwise, 0.
            int weight = (color[node] != color[neighbor]) ? 1 : 0;
            dfs(neighbor, node, current_dist + weight);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1st DFS to find one endpoint of the condensed tree's diameter
    max_dist = -1;
    dfs(1, 0, 0);
    int nodeA = farthest_node;

    // 2nd DFS to find the actual diameter of the condensed tree
    max_dist = -1;
    dfs(nodeA, 0, 0);

    // The answer is (Diameter + 1) / 2
    cout << (max_dist + 1) / 2 << "\n";

    return 0;
}