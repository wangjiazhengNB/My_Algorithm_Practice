#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

// 树边相关
int headEdge[N], edgeNe[N << 1], edgeTo[N << 1], edgeId[N << 1], tcnt;
// 查询相关
int headQuery[N], queryNe[N << 1], queryTo[N << 1], queryIndex[N << 1], qcnt;
// Tarjan 相关
bool visited[N];
int father[N], ans[N];
// 树上差分与父边记录
int parentEdge[N], diff[N];
int n, m;

// 保存每个查询的 a 和 b
struct Query {
    int a, b;
} queries[N];

void build() {
    tcnt = qcnt = 1;
    memset(headEdge, 0, sizeof headEdge);
    memset(headQuery, 0, sizeof headQuery);
    memset(visited, false, sizeof visited);
    memset(diff, 0, sizeof diff);
    memset(parentEdge, 0, sizeof parentEdge);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

// 添加树边（带编号）
void addEdge(int u, int v, int id) {
    edgeNe[tcnt] = headEdge[u];
    edgeTo[tcnt] = v;
    edgeId[tcnt] = id;
    headEdge[u] = tcnt++;
}

// 添加查询
void addQuery(int u, int v, int i) {
    queryNe[qcnt] = headQuery[u];
    queryTo[qcnt] = v;
    queryIndex[qcnt] = i;
    headQuery[u] = qcnt++;
}

// 并查集查找
int find(int i) {
    if (i != father[i]) father[i] = find(father[i]);
    return father[i];
}

// Tarjan 求 LCA，并记录每个节点的父边编号
void tarjan(int u, int f) {
    visited[u] = true;
    for (int e = headEdge[u]; e != 0; e = edgeNe[e]) {
        int v = edgeTo[e];
        if (v != f) {
            parentEdge[v] = edgeId[e];  // 记录子节点的父边编号
            tarjan(v, u);
            father[v] = u;
        }
    }
    for (int e = headQuery[u]; e != 0; e = queryNe[e]) {
        int v = queryTo[e];
        if (visited[v]) {
            ans[queryIndex[e]] = find(v);
        }
    }
}

// 后序遍历计算差分累加值
void dfs(int u, int f) {
    for (int e = headEdge[u]; e != 0; e = edgeNe[e]) {
        int v = edgeTo[e];
        if (v != f) {
            dfs(v, u);
            diff[u] += diff[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    build();

    // 输入树边
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, i);
        addEdge(v, u, i);
    }

    // 输入查询并保存
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        queries[i] = {u, v};
        addQuery(u, v, i);
        addQuery(v, u, i);
    }

    // Tarjan 求所有查询的 LCA
    tarjan(1, 0);

    // 树上差分标记
    for (int i = 1; i <= m; i++) {
        int a = queries[i].a;
        int b = queries[i].b;
        int lca = ans[i];
        diff[a]++;
        diff[b]++;
        diff[lca] -= 2;
    }

    // 计算差分累加值
    dfs(1, 0);

    // 寻找符合条件的最大边编号
    int res = -1;
    for (int v = 2; v <= n; v++) {  // 根节点 1 无父边，从子节点开始遍历
        int eid = parentEdge[v];
        if (diff[v] == m) {  // 这条边被所有 m 个查询路径包含
            if (eid > res) {
                res = eid;
            }
        }
    }

    cout << res << endl;

    return 0;
}