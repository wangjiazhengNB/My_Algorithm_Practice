#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], sums[N], k, n;

int find(int x) {
    int l = 0, r = n, m;
    int ans = -1;
    while (l <= r) {
        m = l + r >> 1;
        if (sums[m] >= x) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> k) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            sums[i + 1] = max(sums[i], sum);
        }
        int ans = 0;
        sum = 0;
        for (int i = 0, pre, len; i < n; i++) {
            sum += a[i];
            pre = find(sum - k);
            len = (pre == -1) ? 0 : (i - pre + 1);
            ans = max(len, ans);
        }
        cout << ans << endl;
    }
    return 0;
}

int main() {
    return 0;
}