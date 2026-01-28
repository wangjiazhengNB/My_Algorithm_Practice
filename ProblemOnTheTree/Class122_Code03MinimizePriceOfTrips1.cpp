#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int LIMIT = 6;

int power;
int price_arr[N];
int nums[N];
int head[N], ne[N << 1], to[N << 1], cnt;
int deep[N];
int stjump[N][LIMIT];
int no, yes;

int log2(int n) {
    int ans = 0;
    while ((1 << ans) <= (n >> 1)) {
        ans++;
    }
    return ans;
}

void add(int u, int v) {
    to[cnt] = v;
    ne[cnt] = head[u];
    head[u] = cnt++;
}

void build(int n) {
    power = log2(n);
    memset(nums, 0, sizeof nums);
    memset(head, 0, sizeof head);
    cnt = 1;
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

void dp(int u, int f) {
    int n = price_arr[u] * nums[u];
    int y = (price_arr[u] / 2) * nums[u];
    for (int e = head[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v != f) {
            dp(v, u);
            n += min(no, yes);
            y += no;
        }
    }
    no = n;
    yes = y;
}

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        build(n);
        for (int i = 0, j = 1; i < n; i++, j++) {
            price_arr[j] = price[i];
        }
        for (auto& edge : edges) {
            int u = edge[0] + 1;
            int v = edge[1] + 1;
            add(u, v);
            add(v, u);
        }
        dfs1(1, 0);
        int u, v, lc, lcfather;
        for (auto& trip : trips) {
            u = trip[0] + 1;
            v = trip[1] + 1;
            lc = lca(u, v);
            lcfather = stjump[lc][0];
            nums[u]++;
            nums[v]++;
            nums[lc]--;
            nums[lcfather]--;
        }
        dfs2(1, 0);
        dp(1, 0);
        return min(no, yes);
    }
};