#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int T, n, cnt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 != 0) cnt++; 
        }
        if (cnt % 2 != 0) {
            cout << 0 << '\n';
            continue;
        }
        if (cnt == 0) {
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans = (ans * 2) % mod;
            }
            cout << ans << '\n';
            continue;
        }
        long long ans = 1;
        for (int i = 0; i < n - 1; i++) {
            ans = (ans * 2) % mod;
        }
        cout << ans << '\n';
    }
}