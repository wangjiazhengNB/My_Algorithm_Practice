#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
int a[N], b[N], n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    vector<bool> vis(n + m + 1, false);
    vector<int> prime((n + m) / 2 + 1);
    int cnt = 0;
    for (int i = 2; i <= n + m; i++) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++) {
            if (i * prime[j] > n + m) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    vector<bool> ans(n + m + 1, false);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = a[i] + b[j];
            if (x > n + m) break;
            if (!vis[x] && x >= 2) {
                ans[x] = true;
            }
        }
    }
    int res = 0;
    for (int i = 2; i <= n + m; i++) {
        if (ans[i]) res++;
    }
    cout << res << '\n';
    return 0;
}