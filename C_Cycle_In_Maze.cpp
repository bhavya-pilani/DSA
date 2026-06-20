#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Direction arrays strictly ordered for lexicographical priority: D, L, R, U
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char dir_names[] = {'D', 'L', 'R', 'U'};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<string> grid(n);
    int start_r = -1, start_c = -1;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                start_r = i;
                start_c = j;
            }
        }
    }

    // 1. Instant check for odd k
    if (k % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // 2. Precompute shortest distances to 'X' using BFS
    // Initialize with a large number (infinity representation)
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;

    q.push({start_r, start_c});
    dist[start_r][start_c] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Note: BFS order doesn't matter here since we just want shortest distance
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '*' && dist[nr][nc] == 1e9) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    // 3. Greedily construct the path
    string ans = "";
    int curr_r = start_r;
    int curr_c = start_c;

    for (int step = 1; step <= k; step++) {
        bool moved = false;
        
        // Try D, then L, then R, then U
        for (int i = 0; i < 4; i++) {
            int nr = curr_r + dr[i];
            int nc = curr_c + dc[i];

            // If the cell is valid and the shortest path home is <= remaining steps
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '*') {
                if (dist[nr][nc] <= k - step) {
                    ans += dir_names[i];
                    curr_r = nr;
                    curr_c = nc;
                    moved = true;
                    break; // Break the inner loop, move to next step
                }
            }
        }

        // If we couldn't make any valid move, it's impossible
        if (!moved) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << ans << "\n";
    return 0;
}