#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll k = 202420242024;

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

bool check(ll m) {
    ll ans = m / 20 + m / 24 - m / lcm(20, 24);
    if (ans >= k) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll l = 202420242024, r = 2e13, m, ans;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}