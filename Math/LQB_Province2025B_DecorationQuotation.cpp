#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int n;

ll qpower(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if ((b & 1) == 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ll pre_xor = 0;
    ll ans = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        pre_xor ^= x;
        if (i < n) {
            ll cnt = qpower(3, n - i - 1);
            ans = (ans + pre_xor * 2 % mod * cnt % mod) % mod;
        }
        else {
            ans = (ans + pre_xor) % mod;
        }
    }
    cout << ans % mod << '\n';
    return 0;
}