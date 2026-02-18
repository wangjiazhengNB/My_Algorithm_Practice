#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k;
int cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    if (k == 0) {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (cnt[i]) ans++;
        }
        cout << ans << "\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        vector<int> w;
        for (int j = i; j < N; j += k) {
            w.push_back(cnt[j]);
        }
        int m = w.size();
        if (m == 0) continue;
        if (m == 1) {
            ans += w[0];
            continue;
        }
        vector<int> dp(m);
        dp[0] = w[0];
        dp[1] = max(w[0], w[1]);
        for (int j = 2; j < m; j++) {
            dp[j] = max(dp[j - 1], dp[j - 2] + w[j]);
        }
        ans += dp[m - 1];
    }
    cout << ans << '\n';
    return 0;
}