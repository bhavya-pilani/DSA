#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Adjacency list representation
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // dist array initialized to -1 (indicating unvisited)
    vector<int> dist(n + 1, -1);
    // parent array to reconstruct the path
    vector<int> parent(n + 1, 0);
    queue<int> q;

    // Start BFS from node 1
    dist[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Optional optimization: Stop early if we reached the destination
        if (u == n) break; 

        // Traverse all connected computers
        for (int v : adj[u]) {
            if (dist[v] == -1) { // If the node is unvisited
                dist[v] = dist[u] + 1;
                parent[v] = u;   // Record where we came from
                q.push(v);
            }
        }
    }

    // Output results
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] << "\n";
        
        // Reconstruct the path backwards
        vector<int> path;
        int curr = n;
        while (curr != 0) {
            path.push_back(curr);
            curr = parent[curr]; // Move to the predecessor
        }
        
        // The path is currently from n to 1. Reverse it to be 1 to n.
        reverse(path.begin(), path.end());
        
        // Print the path
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}