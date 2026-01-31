#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n;
int h[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<unordered_map<int, int>> dp(n);
    int ans = 1;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (h[i] > h[j]) {
                int d = i - j;
                dp[i][d] = max(dp[i][d], dp[j].count(d) ? dp[j][d] + 1 : 2);
                ans = max(ans, dp[i][d]);
            }
        }
    }
    cout << ans << '\n';
}