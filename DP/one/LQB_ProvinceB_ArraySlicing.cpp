#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10005, mod = 1e9 + 7;
ll arr[N], dp[N], mx, mn, n;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        mx = 0, mn = n + 1;
        for (int j = i; j >= 1; j--) {
            if (arr[j] > mx) mx = arr[j];
            if (arr[j] < mn) mn = arr[j];
            if (i - j == mx - mn) dp[i] = (dp[i] + dp[j - 1]) % mod;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}