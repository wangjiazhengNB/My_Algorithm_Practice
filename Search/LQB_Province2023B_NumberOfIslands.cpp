#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int T, n, m, ans, cnt;
int arr[N][N], vis[N][N], v[N][N];
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void dfs(int i, int j) {
    if (vis[i][j] || i < 1 || i > n || j < 1 || j > m || arr[i][j] != 1) return;
    vis[i][j] = cnt;
    for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        dfs(x, y);
    }
}

bool query(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m) return true;
    v[i][j] = 1;
    for (int k = 0; k < 8; k++) {
        int x = i + dir[k][0], y = j + dir[k][1];
        if ((arr[x][y] == 1 && vis[x][y] != cnt) || v[x][y]) continue;
        if (query(x, y)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                if (c == '0') arr[i][j] = 0;
                else arr[i][j] = 1;
            }
        }
        cnt = 2;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis[i][j] || arr[i][j] == 0) continue;
                dfs(i, j);
                cnt++;
                memset(v, 0, sizeof v);
                if (query(i, j)) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}