#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int LIMIT = 16;
int arr[N], log_table[N];
int stmax[N][LIMIT], stmin[N][LIMIT];

void build(int n) {
    log_table[0] = -1;
    for (int i = 1; i <= n; i++) {
        log_table[i] = log_table[i >> 1] + 1;
        stmax[i][0] = arr[i];
        stmin[i][0] = arr[i];
    }
    for (int p = 1; p <= log_table[n]; p++) {
        for (int i = 1; i + (1 << p) - 1 <= n; i++) {
            stmax[i][p] = max(stmax[i][p - 1], stmax[i + (1 << (p - 1))][p - 1]);
            stmin[i][p] = min(stmin[i][p - 1], stmin[i + (1 << (p - 1))][p - 1]);

        }
    }
}

int query(int l, int r) {
    int p = log_table[r - l + 1];
    int a = max(stmax[l][p], stmax[r - (1 << p) + 1][p]);
    int b = min(stmin[l][p], stmin[r - (1 << p) + 1][p]);
    return a - b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(n);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}