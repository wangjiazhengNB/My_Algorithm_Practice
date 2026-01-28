#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int headEdge[N], edgeNe[N << 1], edgeTo[N << 1], tcnt;
int headQuery[N], queryNe[N << 1], queryTo[N << 1], queryIndex[N << 1], qcnt;
bool visited[N];
int father[N], ans[N];
int n, m, root;

void build() {
    tcnt = qcnt = 1;
    memset(headEdge, 0, sizeof headEdge);
    memset(headQuery, 0, sizeof headQuery);
    memset(visited, false, sizeof visited);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

void addEdge(int u, int v) {
    edgeNe[tcnt] = headEdge[u];
    edgeTo[tcnt] = v;
    headEdge[u] = tcnt++;
}

void addQuery(int u, int v, int i) {
    queryNe[qcnt] = headQuery[u];
    queryTo[qcnt] = v;
    queryIndex[qcnt] = i;
    headQuery[u] = qcnt++;
}

int find(int i) {
    if (i != father[i]) father[i] = find(father[i]);
    return father[i];
}

void tarjan(int u, int f) {
    visited[u] = true;
    for (int e = headEdge[u], v; e != 0; e = edgeNe[e]) {
        v = edgeTo[e];
        if (v != f) {
            tarjan(v, u);
            father[v] = u;
        }
    }
    for (int e = headQuery[u], v; e != 0; e = queryNe[e]) {
        v = queryTo[e];
        if (visited[v]) {
            ans[queryIndex[e]] = find(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> root;
    build();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addQuery(u, v, i);
        addQuery(v, u, i);
    }
    tarjan(root, 0);
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}