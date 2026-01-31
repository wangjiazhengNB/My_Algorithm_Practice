#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int t, n, ans;


int solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    if (a == b) {
        return -1;
    }
    int ma = b[n - 1];
    int mi = b[0];
    int ans = INT_MAX;
    for (int i = 0, t; i < n; i++) {
        if (a[i] != b[i]) {
            t = max(ma - a[i], a[i] - mi);
            ans = min(ans, t);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}