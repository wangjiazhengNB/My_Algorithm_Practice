#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
const int M = 200005;
ll head[N], ne[M], to[M], w[M], cnt;
ll dist[N];
bool vis[N];
int n, m, s;

void add(int u, int v, int c) {
    to[cnt] = v;
    ne[cnt] = head[u];
    w[cnt] = c;
    head[u] = cnt++;
}

void build() {
    cnt = 1;
    memset(head, 0, sizeof head);
    fill(dist, dist + N, LLONG_MAX);
}

void dj(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> heap;
    dist[s] = 0;
    heap.push({0, s});
    while (!heap.empty()) {
        auto cur = heap.top();
        heap.pop();
        int d = cur.first;
        int u = cur.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e != 0; e = ne[e]) {
            int v = to[e];
            if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w[e]) {
                dist[v] = dist[u] + w[e];
                heap.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s;
    build();
    for (int i = 1, u, v, c; i <= m; i++) {
        cin >> u >> v >> c;
        add(u, v, c);
    }
    dj(s);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}