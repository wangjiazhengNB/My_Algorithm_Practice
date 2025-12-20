#include <bits/stdc++.h>
using namespace std;

const int N = 6005;

int nums[N], h[N], ne[N], to[N], cnt = 1;
int no[N], yes[N];
int n, root;
bool boss[N];

void add(int u, int v) {
    to[cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt++;
}

void f(int u) {
    no[u] = 0;
    yes[u] = nums[u];
    for (int ei = h[u], v; ei > 0; ei = ne[ei]) {
        v = to[ei];
        f(v);
        no[u] += max(yes[v], no[v]);
        yes[u] += no[v];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(v, u);
        boss[u] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!boss[i]) {
            root = i;
            break;
        }
    }
    f(root);
    cout << max(no[root], yes[root]) << endl;
    return 0;
}