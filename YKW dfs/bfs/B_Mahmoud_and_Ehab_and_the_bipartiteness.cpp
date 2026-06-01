#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];

// Use long long to prevent integer overflow during multiplication!
long long count0 = 0;
long long count1 = 0;

// DFS to color the tree and count the sizes of the two bipartite sets
void dfs(int node, int parent, int color) {
    // Tally the counts based on the current node's color
    if (color == 0) {
        count0++;
    } else {
        count1++;
    }

    // Traverse neighbors
    for (int neighbor : adj[node]) {
        if (neighbor != parent) { // Prevent walking backward in the undirected tree
            // Color the neighbor with the opposite color (1 - color flips 0 to 1, and 1 to 0)
            dfs(neighbor, node, 1 - color);
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start DFS from node 1, parent 0 (dummy), starting with color 0
    dfs(1, 0, 0);

    // Calculate maximum possible edges minus the existing tree edges
    long long max_added_edges = (count0 * count1) - (n - 1);

    cout << max_added_edges << "\n";

    return 0;
}