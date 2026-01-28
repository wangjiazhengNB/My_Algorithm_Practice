#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
ll info1[N], info2[N];

int n, m;

int lowbit(int i) {
    return i & -i;
}

void add(ll tree[], int i, ll v) {
    while (i <= n) {
        tree[i] += v;
        i += lowbit(i);
    }
}

ll sum(ll tree[], int i) {
    ll ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

void add(int l, int r, ll v) {
    add(info1, l, v);
    add(info1, r + 1, -v);
    add(info2, l, (ll)(l - 1) * v);
    add(info2, r + 1, -(ll)r * v);
}

ll range(int l, int r) {
    return sum(info1, r) * r - sum(info2, r) - sum(info1, l - 1) * (l - 1) + sum(info2, l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int op, l, r;
    ll cur, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        add(i, i, cur);
    }
    for (int i - 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> v;
            add(l, r, v);
        }
        else {
            cin >> l >> r;
            cout << range(l, r) << '\n';
        }
    }
}

