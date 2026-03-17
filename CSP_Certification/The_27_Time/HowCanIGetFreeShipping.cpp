#include <bits/stdc++.h>
using namespace std;

int n, x, limit, sum;
int book[35], ans;
int dp[31][500005];

void f(int i, int cost) {
    if (i == n) {
        ans = min(ans, sum - cost);
        return;
    }
    if (dp[i][cost] != -1) return;
    if (book[i] + cost <= limit) {
        f(i + 1, cost + book[i]);
        f(i + 1, cost);
    }
    else {
        f(i + 1, cost);
    }
    dp[i][cost] = 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x;
    for (int i = 0, t; i < n; i++) {
        cin >> book[i];
        sum += book[i];
    }
    limit = sum - x;
    ans = INT_MAX;
    memset(dp, -1, sizeof dp);
    f(0, 0);
    cout << ans << '\n';
    return 0;
}