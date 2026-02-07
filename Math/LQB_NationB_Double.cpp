#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200005;
ll f[N], arr[N];
int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    f[1] = 0;
    for (ll i = 2, x, y; i <= n; i++) {
        f[i] = f[i - 1];
        x = arr[i], y = arr[i - 1];
        while (x >= y * 2) {
            if (f[i] == 0) break;
            y *= 2;
            f[i]--;
        }
        while (x < y) {
            x *= 2;
            f[i]++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += f[i];
    cout << ans << '\n';
    return 0;
}