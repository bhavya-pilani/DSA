#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, k;
vector<string> grid;
vector<vector<bool>> visited;

// Direction arrays for moving Up, Down, Left, Right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c) {
    visited[r][c] = true;
    
    // 1. Visit all connected children first
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        // If neighbor is within bounds, is an empty cell, and hasn't been visited
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == '.') {
            dfs(nr, nc);
        }
    }
    
    // 2. Post-Order step: When returning from the depths, if we still need to place walls,
    // we are safely at a "leaf" of the remaining traversal tree.
    if (k > 0) {
        grid[r][c] = 'X';
        k--;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> k)) return 0;

    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    int start_r = -1, start_c = -1;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        // Find any starting empty cell
        if (start_r == -1) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    start_r = i;
                    start_c = j;
                    break;
                }
            }
        }
    }

    // Run the DFS from the first empty cell we found
    if (start_r != -1) {
        dfs(start_r, start_c);
    }

    // Print the final modified grid
    for (int i = 0; i < n; ++i) {
        cout << grid[i] << "\n";
    }

    return 0;
}