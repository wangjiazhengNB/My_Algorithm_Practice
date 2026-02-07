#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
int n;
string x, y;
ll dp[100005][3]; 

ll f(int i, int carry) {
    if (i == n) return carry != 0 ? INF : 0;
    if (dp[i][carry + 1] != -1) return dp[i][carry + 1]; 
    ll cur = (x[i] - '0') + carry;
    ll target = y[i] - '0';
    ll res = INF;
    res = min(res, abs(cur - target) + f(i + 1, 0));
    res = min(res, abs(cur - (target + 10)) + (i == n-1 ? 0 : f(i + 1, 1)));
    res = min(res, abs(cur - (target - 10)) + (i == n-1 ? 0 : f(i + 1, -1)));
    dp[i][carry + 1] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << '\n';
    return 0;
}