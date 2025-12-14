#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int w[N], v[N], t, m;
int dp[N];

int main() {
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[t];
    return 0;
}