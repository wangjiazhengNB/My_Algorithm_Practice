#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int arr[N], n;

bool f(int m, int maxn, int n) {
    for (int i = 0; i < n; i++) {
        if (m > arr[i]) {
            m += m - arr[i];
        }
        if (m < arr[i]) {
            m -= arr[i] - m;
        }
        if (m >= maxn) return true;
        if (m < 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int l = 0, r = 0, m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    int ans = 0, maxn = r;
    while (l <= r) {
        m = l + ((r - l) >> 1);
        if (f(m, maxn, n)) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << ans;
    return 0;
}
