#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int T = 3005, M = 1505, mod = 1e9 + 7;
ll dp[T][M];
int d, t, m;

int f(int i, int distance, int power) {
    if (distance >= d) return 0;
    if (i == t) {
        if (power == 0) return 1;
        else return 0;
    }
    if (dp[i][power] != -1) return dp[i][power];
    ll ans = 0;
    ans = (ans + f(i + 1, distance + 1, power)) % mod;
    if (power > 0) ans = (ans + f(i + 1, distance - 1, power - 1)) % mod;
    dp[i][power] = ans;
    return (int)ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> d >> t >> m;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, m) << '\n';
    return 0;
}