#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(n);
    dp[0] = v[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + v[i], v[i]);
        
        if (dp[i] > max_sum) {
            max_sum = dp[i];
        }
    }

    cout << max_sum << "\n";

    return 0;
}