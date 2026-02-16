#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<int> arr(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    vector<bool> dp(sum * 2 + 1, false);
    dp[sum] = true;
    for (int i = 1; i <= n; i++) {
        vector<bool> pre_dp = dp;
        for (int x = 0; x <= 2 * sum; x++) {
            if (pre_dp[x]) {
                if (x + arr[i] <= 2 * sum) dp[x + arr[i]] = true;
                if (x - arr[i] >= 0) dp[x - arr[i]] = true;
            }
        }
    }
    int ans = 0;
    for (int x = sum + 1; x <= 2 * sum; x++) {
        if (dp[x]) ans++;
    }
    cout << ans << '\n';
    return 0;
}