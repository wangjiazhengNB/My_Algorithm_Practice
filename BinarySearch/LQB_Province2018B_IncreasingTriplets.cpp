#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N], c[N];
int n, ans;

int bs1(int x) {
    int l = 0, r = n - 1, m, ans = -1;
    while (l <= r) {
        m = l + r >> 1;
        if (a[m] < x) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return ans;
}

int bs2(int x) {
    int l = 0, r = n - 1, m, ans = n;
    while (l <= r) {
        m = l + r >> 1;
        if (c[m] > x) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
} 


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    long long res = 0;
    for (int j = 0, cnt1, cnt2; j < n; j++) {
        cnt1 = bs1(b[j]) + 1;
        cnt2 = bs2(b[j]) + 1;
        cnt2 = n - cnt2 + 1;
        res += (long long)cnt1 * cnt2;
    }
    cout << res << '\n';
    return 0;
}