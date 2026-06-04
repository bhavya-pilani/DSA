#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Direction arrays for the 8 possible King moves
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int start_x, start_y, end_x, end_y;
    if (!(cin >> start_x >> start_y >> end_x >> end_y)) return 0;

    int n;
    cin >> n;

    // Map to store allowed cells and their shortest distance from the start
    // key: {row, col}, value: distance
    map<pair<int, int>, int> dist;

    // Read the allowed segments and populate the map
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int c = a; c <= b; c++) {
            dist[{r, c}] = -1; // -1 marks the cell as allowed but unvisited
        }
    }

    // BFS Queue stores pairs of coordinates
    queue<pair<int, int>> q;

    // Start BFS
    q.push({start_x, start_y});
    dist[{start_x, start_y}] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        // Stop early if we reached the target
        if (r == end_x && c == end_y) break;

        // Check all 8 directions
        for (int i = 0; i < 8; i++) {
            int next_r = r + dx[i];
            int next_c = c + dy[i];

            // If the cell exists in our map (is allowed) AND hasn't been visited yet
            if (dist.count({next_r, next_c}) && dist[{next_r, next_c}] == -1) {
                dist[{next_r, next_c}] = dist[{r, c}] + 1;
                q.push({next_r, next_c});
            }
        }
    }

    // Output the result. If end is not in map or unvisited, it prints -1.
    if (dist.count({end_x, end_y}) && dist[{end_x, end_y}] != -1) {
        cout << dist[{end_x, end_y}] << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}