#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int arr[N][N];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool vis[N][N];
int n;
int sum = 0, ans = 0;

void dfs(int i, int j, bool &is_safe) {
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (!is_safe) {
        int land_cnt = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                if (arr[x][y] != 1) {
                    land_cnt++;
                }
            }
        }
        if (land_cnt == 4) {
            is_safe = true;
            ans++;
        }
    }

    for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y] && arr[x][y] == 0) {
            dfs(x, y, is_safe);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            arr[i][j] = (c == '.') ? 1 : 0;
        }
    }

    for (int i = 2; i <= n-1; i++) {
        for (int j = 2; j <= n-1; j++) {
            if (arr[i][j] == 0 && !vis[i][j]) {
                sum++;
                bool is_safe = false;
                dfs(i, j, is_safe);
            }
        }
    }

    cout << sum - ans << '\n';
    return 0;
}