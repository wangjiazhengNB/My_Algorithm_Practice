#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e6 + 10;
bool vis[N];
ll prime[N];
int cnt = 0;

void is_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++) {
            ll product = (ll)i * prime[j];
            if (product > n) break;
            vis[product] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    is_prime(N);
    const ll PQ_MIN = 49;
    const ll PQ_MAX = 4830458;
    ll ans = 0;
    for (ll i = 0; i < cnt; i++) {
        ll p = prime[i];
        if (p > PQ_MAX) break;
        for (ll j = i + 1; j < cnt; j++) {
            ll q = prime[j];
            ll pq = p * q;
            if (pq > PQ_MAX) break;
            if (pq >= PQ_MIN) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}