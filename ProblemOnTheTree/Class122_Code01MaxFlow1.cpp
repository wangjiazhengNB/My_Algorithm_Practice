#include <bits/stdc++.h>
using namespace std;

const int N = 50001;
const int LIMIT = 16;

int power;
int nums[N];
int head[N];
int ne[N << 1];
int to[N << 1];
int cnt;
int deep[N];
int stjump[N][LIMIT];
int n, m;

int log2() {
    int ans = 0;
    while ((1 << ans) <= (n >> 1)) {
        ans++;
    }
    return ans;
}

void build() {
    power = log2();
    memset(head, 0, sizeof head);
    memset(nums, 0, sizeof nums);
    cnt = 1;
}

void add(int u, int v) {
    to[cnt] = v;
    ne[cnt] = head[u];
    head[u] = cnt++;
}

void dfs1(int u, int f) {
    deep[u] = deep[f] + 1;
    stjump[u][0] = f;
    for (int p = 1; p <= power; p++) {
        stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
    }
    for (int e = head[u]; e != 0; e = ne[e]) {
        if (to[e] != f) {
            dfs1(to[e], u);
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

void dfs2(int u, int f) {
    for (int e = head[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v != f) {
            dfs2(v, u);
        }
    }
    for (int e = head[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v != f) {
            nums[u] += nums[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    build();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs1(1, 0);
    for (int i = 1, u, v, lc, lcfather; i <= m; i++) {
        cin >> u >> v;
        lc = lca(u, v);
        lcfather = stjump[lc][0];
        nums[u]++;
        nums[v]++;
        nums[lc]--;
        nums[lcfather]--;
    }
    dfs2(1, 0);
    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        max_val = max(max_val, nums[i]);
    }
    cout << max_val << '\n';
    return 0;
}