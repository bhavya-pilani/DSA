#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Structure to hold value and the cumulative OR for the stack
struct Node {
    int val;
    int current_or;
};

// Helper to push to a stack and update the cumulative OR
void push_stack(stack<Node>& s, int val) {
    int prev_or = s.empty() ? 0 : s.top().current_or;
    s.push({val, val | prev_or});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * 1LL * arr[i - 1] + b) % c;
    }

    stack<Node> in_stack, out_stack;
    int final_xor = 0;

    // Helper to move elements from in_stack to out_stack
    auto transfer = [&]() {
        while (!in_stack.empty()) {
            int val = in_stack.top().val;
            in_stack.pop();
            push_stack(out_stack, val);
        }
    };

    // Process elements
    for (int i = 0; i < n; i++) {
        // Add current element to in_stack
        push_stack(in_stack, arr[i]);

        // If window is full, we need to process the OR
        if (i >= k - 1) {
            // If out_stack is empty, transfer everything from in_stack
            if (out_stack.empty()) {
                transfer();
            }

            // Get OR of current window
            int or_in = in_stack.empty() ? 0 : in_stack.top().current_or;
            int or_out = out_stack.empty() ? 0 : out_stack.top().current_or;
            final_xor ^= (or_in | or_out);

            // Pop from out_stack to slide the window
            out_stack.pop();
        }
    }

    cout << final_xor << "\n";

    return 0;
}