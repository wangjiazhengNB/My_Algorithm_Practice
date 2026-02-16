#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 50005;
int n, m;
int cnt[N], tmp[N], vis[N], ans, idx;
map<PII, int> mp;

void dfs(int x, int y, int r) {
    for (int i = x - r; i <= x + r; i++) {
        for (int j = y - r; j <= y + r; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) > r * r) continue;
            if (mp.count({i, j})) {
                int z = mp[{i, j}];
                if (vis[z]) continue;
                vis[z] = 1;
                ans += cnt[z];
                dfs(i, j, tmp[z]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1, x, y, z, r; i <= n; i++) {
        cin >> x >> y >> r;
        if (mp.count({x, y})) {
            z = mp[{x, y}];
            cnt[z]++;
            tmp[z] = max(tmp[z], r);
        }
        else {
            mp[{x, y}] = ++idx;
            cnt[idx] = 1, tmp[idx] = r;
        }
    }
    for (int i = 1, x, y, r, z; i <= m; i++) {
        cin >> x >> y >> r;
        dfs(x, y, r);
    }
    cout << ans << '\n';
    return 0;
}