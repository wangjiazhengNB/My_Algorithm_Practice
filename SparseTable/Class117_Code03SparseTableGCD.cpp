#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int LIMIT = 10;

int arr[N], log_table[N], stgcd[N][LIMIT];
int n, m;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void build() {
    log_table[0] = -1;
    for (int i = 1; i <= n; i++) {
        log_table[i] = log_table[i >> 1] + 1;
        stgcd[i][0] = arr[i];
    }
    for (int p = 1; p <= log_table[n]; p++) {
        for (int i = 1; i + (1 << p) - 1 <= n; i++) {
            stgcd[i][p] = gcd(stgcd[i][p - 1], stgcd[i + (1 << (p - 1))][p - 1]);
        }
    }
}

int query(int l, int r) {
    int p = log_table[r - l + 1];
    return gcd(stgcd[l][p], stgcd[r - (1 << p) + 1][p]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build();
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}