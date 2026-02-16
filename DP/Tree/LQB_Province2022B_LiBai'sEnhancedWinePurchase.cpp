#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105, mod = 1e9 + 7;
int n, m;
int dp[N][N][200];

int f(int store, int flower, int liquor) {
    if (store < 0 || flower < 0) return 0;
    if (store <= 0  && flower <= 0) {
        if (store == 0 && flower == 0 && liquor == 2) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dp[store][flower][liquor] != -1) return dp[store][flower][liquor];
    ll ans = 0;
    if (store == n && flower == m && liquor == 0) {
        if (flower > 0) ans = (ans + f(store, flower - 1, liquor + 1)) % mod;
    }
    else {
        if (store > 0 && liquor % 2 == 0) ans = (ans + f(store - 1, flower, liquor / 2)) % mod;
        if (flower > 0) ans = (ans + f(store, flower - 1, liquor + 1)) % mod;
    }
    dp[store][flower][liquor] = ans;
    return (int)ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << f(n, m, 0) << '\n';
    return 0;
}