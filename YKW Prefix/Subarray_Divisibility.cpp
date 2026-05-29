#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    vector<long long> rem_count(n, 0);
    
    rem_count[0] = 1;

    long long current_sum = 0;
    long long valid_subarrays = 0;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        
        current_sum += a;

        long long rem = (current_sum % n + n) % n;

     
        valid_subarrays += rem_count[rem];

        rem_count[rem]++;
    }

    cout << valid_subarrays << "\n";

    return 0;
}