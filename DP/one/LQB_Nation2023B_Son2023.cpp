#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[4] = {0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    for (ll i = 1; i <= 2023; i++) {
        s += to_string(i);
    }
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == '2') {
            dp[0]++;
            dp[2] += dp[1];
        }
        else if (s[i] == '0') {
            dp[1] += dp[0];
        }
        else if (s[i] == '3') {
            dp[3] += dp[2];
        }
    }
    cout << dp[3] << '\n';
    return 0;
}