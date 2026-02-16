#include <bits/stdc++.h>
using namespace std;

const int N = 40005;
bitset<N> dp[N];
int c[N];
int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        dp[i][c[i]] = 1;
        if (i + c[i] <= n) {
            dp[i] |= dp[i + c[i]];
        }
        if (2 * i <= n) {
            dp[i] |= dp[2 * i];
        }
        ans = max(ans, (int)dp[i].count());
    }
    cout << ans << '\n';
    return 0;
}