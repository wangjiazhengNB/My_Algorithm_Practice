#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e7 + 5;
const int mod = 1e9 + 7;
ll dp[N];
int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 5;
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2 + dp[i - 3] + dp[i - 4]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}


