#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll a = 1, sum = 0;
    for (int i = 1; i <= 39; i++) {
        a = (a * i) % mod;
        sum = (sum + a) % mod;
    }
    cout << sum << '\n';
    return 0;
}