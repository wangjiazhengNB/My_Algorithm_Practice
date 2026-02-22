#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 505, X = 100005;
ll dp[X], n, x, cnt = 1;
ll w[N], v[N];

ll compute() {
    for (int i = 1; i <= cnt; i++) {
        for (int j = x; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, wi;
        cin >> a >> b >> wi;
        int t = (a - b) - b;
        if (t >= 0) {
            ans += wi;
            x += t;
        }
        else {
            w[cnt] = -t;
            v[cnt++] = wi;
        }
    }
    ans += compute();
    cout << ans;
}