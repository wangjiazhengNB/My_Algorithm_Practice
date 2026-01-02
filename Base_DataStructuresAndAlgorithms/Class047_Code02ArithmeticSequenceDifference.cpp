#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000005;
long long arr[MAXN];
int n, m;

void set_(int l, int r, int s, int e, int d) {
    arr[l] += s;
    arr[l + 1] += (long long)d - s;
    arr[r + 1] -= (long long)d + e;
    arr[r + 2] += e;
}

void build() {
    for (int i = 1; i <= n; ++i) {
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        arr[i] += arr[i - 1];
    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < m; ++i) {
            int l, r, s, e;
            scanf("%d%d%d%d", &l, &r, &s, &e);
            int d = (e - s) / (r - l);
            set_(l, r, s, e, d);
        }
        build();
        long long max_val = 0;
        long long xor_val = 0;
        for (int i = 1; i <= n; ++i) {
            max_val = max(max_val, arr[i]);
            xor_val ^= arr[i];
        }
        printf("%lld %lld\n", xor_val, max_val);
    }
    return 0;
}