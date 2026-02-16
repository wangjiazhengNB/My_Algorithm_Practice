#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;
ll arr[N], dp[N], n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        arr[i + 1] = s[i] - 'a' + 1;
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], dp[i - 2] + arr[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}