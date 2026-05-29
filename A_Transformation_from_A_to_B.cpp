#include <iostream>
#include <vector>

using namespace std;

// DFS function to explore the paths
bool dfs(long long current, long long target, vector<long long>& path) {
    // Add current number to our ongoing path
    path.push_back(current);

    // Base Case 1: We hit the target
    if (current == target) {
        return true;
    }

    // Base Case 2: We overshot the target (Dead End)
    if (current > target) {
        path.pop_back(); // Backtrack: remove current before returning
        return false;
    }

    // Branch 1: Try multiplying by 2
    if (dfs(current * 2, target, path)) {
        return true; // If this branch found the target, instantly return true
    }

    // Branch 2: Try appending 1 (Wait to do this until Branch 1 finishes/fails)
    if (dfs(current * 10 + 1, target, path)) {
        return true; 
    }

    // If both branches failed, this 'current' node is a dead end
    path.pop_back(); // Backtrack
    return false;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    vector<long long> path;

    // Start the DFS from 'a'
    if (dfs(a, b, path)) {
        cout << "YES\n";
        cout << path.size() << "\n";
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}