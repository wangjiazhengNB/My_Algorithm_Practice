#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int tree[N];

int n, m;

int lowbit(int i) {
    return i & -i;
}

void add(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += lowbit(i);
    }
}

// 返回1~i范围累加和
int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

// 区间查询[l, r]的和
int range(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1, v; i <= n; ++i) {
        cin >> v;
        add(i, v);
    }
    for (int i = 1, a, b, c; i <= m; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            add(b, c);
        } else {
            cout << range(b, c) << endl;
        }
    }
    return 0;  
}