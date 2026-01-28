#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LIMIT = 18;

struct Line {
    int id;
    int l, r;
}line[N << 1];

int power;
int stjump[N << 1][LIMIT];
int ans[N];
int n, m;

int log2(int n) {
    int res = 0;
    while ((1 << res) <= (n >> 1)) {
        res++;
    }
    return res;
}

bool cmp(const Line& a, const Line& b) {
    return a.l < b.l;
}

void build() {
    for (int i = 1; i <= n; i++) {
        if (line[i].l > line[i].r) {
            line[i].r += m;
        }
    }
    sort(line + 1, line + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        line[i + n].id = line[i].id;
        line[i + n].l = line[i].l + m;
        line[i + n].r = line[i].r + m;
    }
    int e = n << 1;
    for (int i = 1, arrive = 1; i <= e; i++) {
        while (arrive + 1 <= e && line[arrive + 1].l <= line[i].r) {
            arrive++;
        }
        stjump[i][0] = arrive;
    }
    //倍增
    for (int p = 1; p <= power; p++) {
        for (int i = 1; i <= e; i++) {
            stjump[i][p] = stjump[stjump[i][p - 1]][p - 1];
        }
    }
}

int jump(int i) {
    int aim = line[i].l + m;
    int cur = i;
    int res = 1;
    for (int p = power; p >= 0; p--) {
        int next = stjump[cur][p];
        if (next != 0 && line[next].r < aim) {
            res += 1 << p;
            cur = next;
        }
    }
    return res + 1;
}

void compute() {
    power = log2(n);
    build();
    for (int i = 1; i <= n; i++) {
        ans[line[i].id] = jump(i);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        line[i].id = i;
        cin >> line[i].l >> line[i].r;
    }
    compute();
    cout << ans[1];
    for (int i = 2; i <= n; i++) {
        cout << " " << ans[i];
    }
    cout << '\n';
    return 0;
}