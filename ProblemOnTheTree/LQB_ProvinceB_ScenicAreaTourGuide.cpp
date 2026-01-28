#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
const int LIMIT = 20;
int power;
int nums[N];
int travel[N];
int stjump[N][LIMIT];
int deep[N];
int head[N], ne[N << 1], to[N << 1], w[N << 1], cnt;
ll ans[N], dist[N];
int n, k;

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

void add(int u, int v, int c) {
    to[cnt] = v;
    w[cnt] = c;
    ne[cnt] = head[u];
    head[u] = cnt++;
}

void dfs1(int u, int f) {
    deep[u] = deep[f] + 1;
    stjump[u][0] = f;
    for (int p = 1; p <= power; p++) {
        stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
    }
    for (int e = head[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v != f) {
            dist[v] = dist[u] + w[e];
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

ll get_path_sum(int a, int b) {
    int lc = lca(a, b);
    return dist[a] + dist[b] - 2 * dist[lc];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    build();
    for (int i = 1, u, v, c; i < n; i++) {
        cin >> u >> v >> c;
        add(u, v, c);
        add(v, u, c);
    }
    for (int i = 1; i <= k; i++) {
        cin >> travel[i];
    }
    dfs1(1, 0);
    int u, v, lc, lcfather;
    for (int i = 1; i < k; i++) {
        u = travel[i];
        v = travel[i + 1];
        lc = lca(u, v);
        nums[u]++;
        nums[v]++;
        nums[lc]--;
        if (stjump[lc][0] != 0) {
            nums[stjump[lc][0]]--;
        }
    }
    dfs2(1, 0);
    ll total = 0;
    for (int i = 1; i < k; i++) {
        total += get_path_sum(travel[i], travel[i + 1]);
    }
    for (int i = 1; i <= k; i++) {
        if (i == 1) {
            ll del = get_path_sum(travel[1], travel[2]);
            ans[i] = total - del;
        }
        else if (i == k) {
            ll del = get_path_sum(travel[k - 1], travel[k]);
            ans[i] = total - del;
        }
        else {
            ll path1 = get_path_sum(travel[i - 1], travel[i]);
            ll path2 = get_path_sum(travel[i], travel[i + 1]);
            ll path3 = get_path_sum(travel[i - 1], travel[i + 1]);
            ll save = path1 + path2 - path3;
            ans[i] = total - save;
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}