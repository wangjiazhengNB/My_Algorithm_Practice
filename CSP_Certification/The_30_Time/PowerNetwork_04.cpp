#include <bits/stdc++.h>
using namespace std;


// 20分写法，暴力

/*
struct Edge {
    int u, v; 
    int t[10][10]; 
} edges[20]; 

int a[6][10];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                cin >> edges[i].t[x][y];
            }
        }
    }

    long long total_plan = 1;
    for (int i = 0; i < n; i++) {
        total_plan *= k;
    }
    int min_total = INT_MAX;
    int choice[6];
    for (int i = 0; i < total_plan; i++) {
        int total = 0;
        int tmp = i;
        // 把当前数字拆成k进制，每一位对应一个城镇的选址
        for (int i = 0; i < n; i++) {
            choice[i] = tmp % k;
            tmp /= k;
        }
        for (int i = 0; i < n; i++) {
            total += a[i][choice[i]];
        }
        for (int i = 0; i < m; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            total += edges[i].t[choice[u]][choice[v]];
        }
        if (total < min_total) {
            min_total = total;
        }
    }
    
    cout << min_total << endl;
    return 0;
}
*/

// 40分写法（标准树上DP）
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 10005;
const int MAXK = 10;
ll n, m, k, h[MAXN], to[MAXN << 1], ne[MAXN << 1], cost[MAXN << 1][MAXK][MAXK], cnt;
ll a[MAXN][MAXK], dp[MAXN][MAXK];

void build() {
    cnt = 1;
    memset(h, 0, sizeof h);
}

void add(int u, int v, ll c[][MAXK]) {
    to[cnt] = v;
    ne[cnt] = h[u];
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            cost[cnt][x][y] = c[x][y];
        }
    }
    h[u] = cnt++;
}

void dfs(int u, int f) {
    for (int x = 0; x < k; x++) {
        dp[u][x] = a[u][x];
    }
    for (int e = h[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v != f) {
            dfs(v, u);
            for (int x = 0; x < k; x++) {
                ll min_val = INF;
                for (int y = 0; y < k; y++) {
                    min_val = min(min_val, dp[v][y] + cost[e][x][y]);
                }
                dp[u][x] += min_val;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    build();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ll c[MAXK][MAXK];
        ll rc[MAXK][MAXK];
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                cin >> c[x][y];
                rc[y][x] = c[x][y];
            }
        }
        add(u, v, c);
        add(v, u, rc);
    }
    dfs(0, -1);
    ll ans = INF;
    for (int i = 0; i < k; i++) {
        ans = min(ans, dp[0][i]);
    }
    cout << ans << '\n';
    return 0;
}
*/

// 60分写法，条件加上基环树的判断
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 10005;
const int MAXK = 10;
ll n, m, k, h[MAXN], to[MAXN << 1], ne[MAXN << 1], cost[MAXN << 1][MAXK][MAXK], cnt;
ll a[MAXN][MAXK], dp[MAXN][MAXK];
ll fa[MAXN];
int ring_s, ring_t, ring_c[MAXK][MAXK];

void build() {
    cnt = 1;
    memset(h, 0, sizeof h);
    for (int i = 0; i < n; i++) fa[i] = i;
}

ll find(ll x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void add(int u, int v, ll c[][MAXK]) {
    to[cnt] = v;
    ne[cnt] = h[u];
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            cost[cnt][x][y] = c[x][y];
        }
    }
    h[u] = cnt++;
}

void dfs(int u, int f) {
    for (int x = 0; x < k; x++) {
        dp[u][x] = a[u][x];
    }
    for (int e = h[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v != f) {
            dfs(v, u);
            for (int x = 0; x < k; x++) {
                ll min_val = INF;
                for (int y = 0; y < k; y++) {
                    min_val = min(min_val, dp[v][y] + cost[e][x][y]);
                }
                dp[u][x] += min_val;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    build();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;

        ll c[MAXK][MAXK];
        ll rc[MAXK][MAXK];
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                cin >> c[x][y];
                rc[y][x] = c[x][y];
            }
        }
        int fu = find(u);
        int fv = find(v);
        if (fu == fv) {
            ring_s = u;
            ring_t = v;
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    ring_c[x][y] = c[x][y];
                }
            }
        }
        else {
            add(u, v, c);
            add(v, u, rc);
        }
    }
    dfs(0, -1);
    ll ans = INF;
    if (m == n - 1) {
        dfs(0, -1);
        for (int i = 0; i < k; i++) {
        ans = min(ans, dp[0][i]);
    }
    }
    else {
        dfs(ring_s, -1);
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                ans = min(ans, dp[ring_s][x] + ring_c[x][y]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
*/

// 80分写法，加上子任务4的特殊条件，单枢纽D，单独枚举D状态即可
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 10005;
const int MAXK = 10;

int n, m, k;
ll h[MAXN], to[MAXN << 1], ne[MAXN << 1], cost[MAXN << 1][MAXK][MAXK], cnt;
ll a[MAXN][MAXK], dp[MAXN][MAXK];
int deg[MAXN];

int fa[MAXN];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int ring_s, ring_t;
ll ring_c[MAXK][MAXK];

void build() {
    cnt = 1;
    memset(h, 0, sizeof h);
    memset(deg, 0, sizeof deg);
    for (int i = 0; i < n; i++) fa[i] = i;
}

void add(int u, int v, ll c[][MAXK]) {
    to[cnt] = v;
    ne[cnt] = h[u];
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            cost[cnt][x][y] = c[x][y];
        }
    }
    h[u] = cnt++;
}

void dfs(int u, int f) {
    for (int x = 0; x < k; x++) {
        dp[u][x] = a[u][x];
    }
    for (int e = h[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v != f) {
            dfs(v, u);
            for (int x = 0; x < k; x++) {
                ll min_val = INF;
                for (int y = 0; y < k; y++) {
                    min_val = min(min_val, dp[v][y] + cost[e][x][y]);
                }
                dp[u][x] += min_val;
            }
        }
    }
}

ll dfs_chain(int u, int f, int root_state) {
    ll res = INF;
    for (int x = 0; x < k; x++) dp[u][x] = a[u][x];
    for (int e = h[u], v; e != 0; e = ne[e]) {
        v = to[e];
        if (v == f) continue;
        dfs_chain(v, u, root_state);
        for (int x = 0; x < k; x++) {
            ll mn = INF;
            for (int y = 0; y < k; y++) mn = min(mn, dp[v][y] + cost[e][x][y]);
            dp[u][x] += mn;
        }
    }
    if (f == -1) {
        for (int x = 0; x < k; x++) res = min(res, dp[u][x] + cost[0][root_state][x]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    build();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        ll c[MAXK][MAXK];
        ll rc[MAXK][MAXK];
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                cin >> c[x][y];
                rc[x][y] = c[y][x];
            }
        }

        deg[u]++, deg[v]++;
        int fu = find(u), fv = find(v);
        if (fu == fv) {
            ring_s = u, ring_t = v;
            memcpy(ring_c, c, sizeof ring_c);
        } else {
            fa[fu] = fv;
            add(u, v, c);
            add(v, u, rc);
        }
    }

    ll ans = INF;
    if (m == n-1) {
        dfs(0, -1);
        for (int i = 0; i < k; i++) ans = min(ans, dp[0][i]);
    }
    else if (m == n) {
        dfs(ring_s, -1);
        for (int x = 0; x < k; x++)
            for (int y = 0; y < k; y++)
                ans = min(ans, dp[ring_s][x] + ring_c[x][y]);
    }
    else {
        int D = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] > 2) { D = i; break; }
        }
        for (int x = 0; x < k; x++) {
            ll total = a[D][x];
            for (int e = h[D], v; e; e = ne[e]) {
                v = to[e];
                memcpy(cost[0], cost[e], sizeof cost[e]);
                total += dfs_chain(v, D, x);
            }
            ans = min(ans, total);
        }
    }

    cout << ans << '\n';
    return 0;
}