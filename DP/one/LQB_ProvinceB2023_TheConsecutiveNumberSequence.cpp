#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int len = s.size();
        dp[s[len - 1] - '0'] = max(dp[s[len - 1] - '0'], dp[s[0] - '0'] + 1);
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;
    return 0;
}