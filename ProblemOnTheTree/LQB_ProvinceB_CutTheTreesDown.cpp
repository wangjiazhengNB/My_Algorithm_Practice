#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int LIMIT = 18;
int power;
int nums[N];
int stjump[N][LIMIT];
int head[N], ne[N << 1], to[N << 1], cnt;
int deep[N];
int n, m;
int edge_id[N << 1];
int son_edge_id[N];

int log2() {
    int ans = 0;
    while ((1 << ans) <= (n >> 1)) {
        ans++;
    }
    return ans;
}

void build() {
    power = log2();
    cnt = 1;
    memset(head, 0, sizeof head);
    memset(nums, 0, sizeof nums);
}

void add(int u, int v, int id) {
    to[cnt] = v;
    ne[cnt] = head[u];
    edge_id[cnt] = id;
    head[u] = cnt++;
}

void dfs1(int u, int f) {
    deep[u] = deep[f] + 1;
    stjump[u][0] = f;
    for (int p = 1; p <= power; p++) {
        stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
    }
    for (int e = head[u]; e != 0; e = ne[e]) {
        int v = to[e];
        if (v != f) {
            son_edge_id[v] = edge_id[e];
            dfs1(v, u);
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
    for (int e = head[u]; e != 0; e = ne[e]) {
        int v = to[e];
        if (v != f) {
            dfs2(v, u);
        }
    }
    for (int e = head[u], v, w; e != 0; e = ne[e]) {
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
        add(u, v, i);
        add(v, u, i);
    }
    dfs1(1, 0);
    for (int i = 1, u, v, lc; i <= m; i++) {
        cin >> u >> v;
        lc = lca(u, v);
        nums[u]++;
        nums[v]++;
        nums[lc] -= 2;
    }
    dfs2(1, 0);
    int ans = -1;
    for (int v = 2; v <= n; v++) {
        if (nums[v] == m) {
            ans = max(ans, son_edge_id[v]);
        }
    }
    cout << ans << endl;
}