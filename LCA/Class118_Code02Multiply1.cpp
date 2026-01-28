#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int LIMIT = 20;

int power;
int head[N], to[N << 1], ne[N << 1], cnt;
int deep[N], stjump[N][LIMIT];
int n, m, root;

int log2() {
    int ans = 0;
    while ((1 << ans) <= (n >> 1)) {
        ans++;
    }
    return ans;
}

void build() {
    power = log2(n);
    cnt = 1;
    memset(head, 0, sizeof head);
}

void add(int u, int v) {
    to[cnt] = v;
    ne[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int u, int f) {
    deep[u] = deep[f] + 1;
    stjump[u][0] = f;
    for (int p = 1; p <= power; p++) {
        stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
    }
    // 链式前向星遍历子节点，避免走回父节点
    for (int e = head[u]; e != 0; e = ne[e]) {
        if (to[e] != f) {
            dfs(to[e], u);
        }
    }
}

int lca(int a, int b) {
    if (deep[a] < deep[b]) {
        swap(a, b);
    }
    for (int p = power; p >= 0; p--) {
        if (deep[stjump[a][p]] >= deep[b]) {
            a = stjump[a][p];
        }
    }
    if (a == b) {
        return a;
    }
    for (int p = power; p >= 0; p--) {
        if (stjump[a][p] != stjump[b][p]) {
            a = stjump[a][p];
            b = stjump[b][p];
        }
    }
    return stjump[a][0];
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> root;
    // 初始化构建参数
    build();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    // DFS预处理深度和stjump表
    dfs(root, 0);
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}