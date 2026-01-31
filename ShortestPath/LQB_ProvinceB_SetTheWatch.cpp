#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 100005;
const int M = 1000005;
int head[N], ne[M], to[M], cnt;
int dist[N];
bool vis[N];
int n, k;

void build() {
    cnt = 1;
    fill(head, head + N, 0);
    fill(dist, dist + N, INT_MAX);
    memset(vis, false, sizeof vis);
}

void add(int u, int v) {
    to[cnt] = v;
    ne[cnt] = head[u];
    head[u] = cnt++;
}

void dj(int s) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    dist[s] = 0;
    while (!heap.empty()) {
        auto cur = heap.top();
        heap.pop();
        int u = cur.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e != 0; e = ne[e]) {
            int v = to[e];
            if (dist[u] != INT_MAX) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    heap.push({dist[v], v});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    build();
    for (int i = 1; i <= n; i++) {
        int i1 = (i + 1) % n == 0 ? n : (i + 1) % n;
        int i2 = (i + k) % n == 0 ? n : (i + k) % n;
        add(i, i1);
        add(i, i2);
    }
    dj(1);
    int ans = -1;
    for (int i = 2; i <= n; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans << '\n';
    return 0;
}