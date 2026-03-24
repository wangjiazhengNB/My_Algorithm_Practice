#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 20005;
const ll INF = 1e18;  // long long 专用无穷大

// 邻接表：存 {终点节点, 边权}
vector<pair<int, ll>> mp[N];
struct Node {
    int x, y;
    int id;

    bool operator<(const Node& C) const {
        if (x != C.x) return x < C.x;
        return y < C.y;
    }
} node[N];
int n, m;

ll dist[N];
bool vis[N];


void dijkstra(int start) {
    fill(dist, dist + N, INF);
    memset(vis, false, sizeof vis);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> heap;
    heap.push({0, start});
    dist[start] = 0;

    while (!heap.empty()) {
        auto [d, u] = heap.top();
        heap.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : mp[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                heap.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].x >> node[i].y;
        node[i].id = i;
    }

    sort(node + 1, node + n + 1);

    int virtual_id = n + 1;

    for (int i = 1; i <= m; i++) {
        int x, y, r, t;
        cin >> x >> y >> r >> t;
        int up = max(0, y - r);
        int down = y + r;
        int left = max(0, x - r);
        int right = x + r;
        
        int node_l = lower_bound(node + 1, node + n + 1, Node{left, 0, 0}) - node;
        int node_r = upper_bound(node + 1, node + n + 1, Node{right, 1000000000, 0}) - node - 1;

        vector<int> a;
        for (int j = node_l; j <= node_r; j++) {
            if (node[j].y >= up && node[j].y <= down) {
                a.push_back(node[j].id);
            }
        }

        if (a.empty()) continue;

        for (int u : a) {
            mp[u].emplace_back(virtual_id, t);   
            mp[virtual_id].emplace_back(u, 0);   
        }
        virtual_id++;
    }

    dijkstra(1);

    if (dist[n] == INF) cout << "Nan\n";
    else cout << dist[n] << '\n';
    return 0;
}