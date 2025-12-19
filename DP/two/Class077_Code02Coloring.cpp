#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strangePrinter(string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[n - 1][n - 1] = 1;
        for (int i = 0; i < n - 1; i++) {
            dp[i][i] = 1;
            dp[i][i + 1] = s[i] == s[i + 1] ? 1 : 2;
        }
        for (int l = n - 3; l >= 0; l--) {
            for (int r = l + 2; r < n; r++) {
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l][r - 1];
                }
                else {
                    int ans = INT_MAX;
                    for (int m = l; m < r; m++) {
                        ans = min(ans, dp[l][m] + dp[m + 1][r]);
                    }
                    dp[l][r] = ans;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.strangePrinter(s);
}