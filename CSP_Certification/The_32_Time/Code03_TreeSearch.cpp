#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

const int N = 2005;
int w[N];
int to[N], ne[N], h[N], cnt;
int n, m;
int sum_total = 0; // 修复：初始化总权重（编译+逻辑优化）
bool alive[N];
bitset<N> desc[N];

void build() {
    cnt = 1;
    memset(h, 0, sizeof h);
}

void add(int u, int v) {
    to[cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt++;
}

void dfs(int u) {
    desc[u].reset();
    desc[u].set(u);
    for (int e = h[u]; e != 0; e = ne[e]) {
        int v = to[e];
        dfs(v);
        desc[u] |= desc[v];
    }
}

int get_s(int u) {
    int s = 0;
    for (int v = 1; v <= n; v++) {
        if (desc[u][v] && alive[v]) s += w[v];
    }
    return s;
}

int get_current_total() {
    int s = 0;
    for (int v = 1; v <= n; v++) {
        if (alive[v]) s += w[v];
    }
    return s;
}

struct Node {
    int id;
    int w;

    bool operator<(const Node& C) const {
        if (w == C.w) return id < C.id;
        return w < C.w;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    build();

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sum_total += w[i];
    }

    for (int i = 2; i <= n; i++) { 
        int p;
        cin >> p;
        add(p, i); 
    }

    dfs(1);

    while (m--) {
        int q;
        cin >> q;
        int sum_current = sum_total;
        vector<int> ans;
        memset(alive, true, sizeof alive);
        
        while (1) {
            int cnt_alive = 0;
            for (int i = 1; i <= n; i++) {
                if (alive[i]) cnt_alive++;
            }
            if (cnt_alive == 1) break;

            vector<Node> nodes;
            for (int u = 1; u <= n; u++) {
                if (!alive[u]) continue;
                int sum = get_s(u);
                int wd = abs(2 * sum - sum_current);
                nodes.push_back({u, wd});
            }

            sort(nodes.begin(), nodes.end());

            int u = nodes[0].id;
            ans.push_back(u);

            if (desc[u][q]) {
                for (int v = 1; v <= n; v++) {
                    if (!desc[u][v]) alive[v] = false;
                }
            } else {
                for (int v = 1; v <= n; v++) {
                    if (desc[u][v]) alive[v] = false;
                }
            }

            sum_current = get_current_total();
        }


        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }

    return 0;
}