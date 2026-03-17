#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    int l;
    int r;
    int val;

    Node(int l, int r, int val) : l(l), r(r), val(val) {}

    bool operator<(const Node& C) const {
        return l < C.l;
    }
};

set<Node> st;
unordered_map<int, vector<set<Node>::iterator>> val_nodes;
vector<int> p;
vector<int> rp;
vector<ll> cnt;

int n, m, q;

auto split(int pos) {
    if (pos > n) return st.end();

    auto it = st.lower_bound(Node(pos, 0, 0));

    if (it != st.end() && it->l == pos) return it;

    it--;
    int old_l = it->l;
    int old_r = it->r;
    int old_val = it->val;

    auto& vec = val_nodes[old_val];
    for (auto iter = vec.begin(); iter != vec.end();) {
        if (*iter == it) iter = vec.erase(iter);
        else iter++;
    }
    st.erase(it);

    auto left_it = st.insert(Node(old_l, pos - 1, old_val)).first;
    auto right_it = st.insert(Node(pos, old_r, old_val)).first;

    val_nodes[old_val].push_back(left_it);
    val_nodes[old_val].push_back(right_it);

    return right_it;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;

    p.resize(m + 1);
    rp.resize(m + 1);
    cnt.resize(m + 1);

    for (int i = 0; i <= m; i++) {
        p[i] = i;
        rp[i] = i;
    }

    auto init_it = st.insert(Node(1, n, 0)).first;
    val_nodes[0].push_back(init_it);
    cnt[0] = n;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            auto it_r = split(r + 1);
            auto it_l = split(l);

            for (auto it = it_l; it != it_r;) {
                int old_v = it->val;
                cnt[old_v] -= it->r - it->l + 1;

                auto& vec = val_nodes[old_v];

                for (auto iter = vec.begin(); iter != vec.end();) {
                    if (*iter == it) iter = vec.erase(iter);
                    else iter++;
                }

                it = st.erase(it);
            }

            int new_v = p[x];
            auto new_it = st.insert(Node(l, r, new_v)).first;
            cnt[new_v] += r - l + 1;
            val_nodes[new_v].push_back(new_it);
        }

        else if (op == 2) {
            int x, y;
            cin >> x >> y;
            if (x == y) continue;

            int u = p[x];
            int v = p[y];
            if (u == v) continue;

            if (cnt[u] > cnt[v]) {
                swap(p[x], p[y]);
                swap(rp[u], rp[v]);
                swap(u, v);
            }

            for (auto it : val_nodes[u]) {
                int l = it->l;
                int r = it->r;
                st.erase(it);
                auto new_it = st.insert(Node(l, r, u)).first;
                val_nodes[v].push_back(new_it);
                cnt[v] += r - l + 1;
            }

            val_nodes[u].clear();
            cnt[u] = 0;
        }

        else if (op == 3) {
            int x, y;
            cin >> x >> y;
            swap(p[x], p[y]);
            swap(rp[x], rp[y]);
        }

        else if (op == 4) {
            int w;
            cin >> w;
            cout << cnt[p[w]] << '\n';
        }

        else if (op == 5) {
            ll max_len = 0;
            int ans = 0;

            for (int i = 1; i <= m; i++) {
                if (cnt[i] > max_len) {
                    max_len = cnt[i];
                    ans = rp[i];
                }
                else if (cnt[i] == max_len && rp[i] < ans) {
                    ans = rp[i];
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}