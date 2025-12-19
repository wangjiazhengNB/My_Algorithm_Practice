#include <bits/stdc++.h>
using namespace std;

int f(string& s, int l, int r, vector<vector<int>>& dp) {
    if (l == r) return 1;
    if (l == r - 1) {
        if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']')) {
            return 0;
        }
        return 2;
    }
    if (dp[l][r] != -1) return dp[l][r];
    int p1 = INT_MAX;
    if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']')) {
        p1 = f(s, l + 1, r - 1, dp);
    }
    int p2 = INT_MAX;
    for (int k = l; k < r; k++) {
        p2 = min(p2, f(s, l, k, dp) + f(s, k + 1, r, dp));
    }
    int ans = min(p1, p2);
    dp[l][r] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << f(s, 0, n - 1, dp);
}
