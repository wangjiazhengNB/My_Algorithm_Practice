#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n; // 当前测试的小N
int m; // 总格子数 m=2*n
bool vis[3][15]; // 仅用于小N（n≤10），vis[1][j]和vis[2][j]表示两行
int dir[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

// 纯暴力DFS：当前在(x,y)，已经走了cnt个格子
ll dfs(int x, int y, int cnt) {
    if (cnt == m) {
        return 1; // 走完全部格子，找到1条合法路径
    }
    ll res = 0;
    for (int k = 0; k < 8; k++) {
        int nx = x + dir[k][0];
        int ny = y + dir[k][1];
        // 检查边界：行1~2，列1~n，且未访问
        if (nx >= 1 && nx <= 2 && ny >= 1 && ny <= n && !vis[nx][ny]) {
            vis[nx][ny] = true; // 标记为已访问
            res += dfs(nx, ny, cnt + 1);
            vis[nx][ny] = false; // 【关键！】回溯：取消标记，恢复状态
        }
    }
    return res;
}

// 计算2*n网格的总方案数
ll get_dp(int input_n) {
    n = input_n;
    m = 2 * n;
    ll total = 0;
    // 枚举所有起点
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            memset(vis, 0, sizeof(vis)); // 每次换起点都要重置vis
            vis[i][j] = true; // 【关键！】起点必须先标记为已访问
            total += dfs(i, j, 1); // cnt从1开始（已经走了起点）
        }
    }
    return total;
}

int main() {
    // 测试小N，输出dp[1]~dp[5]
    for (int i = 1; i <= 5; i++) {
        cout << "dp[" << i << "] = " << get_dp(i) << endl;
    }
    return 0;
}