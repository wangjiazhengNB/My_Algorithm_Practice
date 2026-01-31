#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 10005, M = 100005;
int dist[N], wet[N];
bool vis[N];
int head[N], to[M], ne[M], w[M], cnt;
int n, m;

void add(int u, int v, int c) {
    to[cnt] = v;
    ne[cnt] = head[u];
    w[cnt] = c;
    head[u] = cnt++;
}

void build() {
    cnt = 1;
    fill(head, head + N, 0);
    fill(dist, dist + N, INT_MAX);
}

void dj() {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dist[1] = 0;
    while (!heap.empty()) {
        auto cur = heap.top();
        heap.pop();
        int u = cur.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e != 0; e = ne[e]) {
            int v = to[e];
            if (dist[u] != INT_MAX) {
                int d = w[e] + wet[v];
                if (dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;
                    heap.push({dist[v], v});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> wet[i];
    }
    build();
    for (int i = 1, u, v, c; i <= m; i++) {
        cin >> u >> v >> c;
        add(u, v, c);
        add(v, u, c);
    }
    dj();
    cout << dist[n] - wet[n] << '\n';
    return 0;
}
