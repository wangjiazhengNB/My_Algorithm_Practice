#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //递归暴力写法
    bool f1(string& s, string& p, int i, int j) {
        if (i == s.size()) {
            if (j == p.size()) return true;
            else {
                return j + 1 < p.size() && p[j + 1] == '*' && f1(s, p, i, j + 2);
            }
        }
        else if (j == p.size()) return false;
        else {
            if (j + 1 == p.size() || p[j + 1] != '*') {
                return (s[i] == p[j] || p[j] == '.') && f1(s, p, i + 1, j + 1);
            }
            else {
                bool p1 = f1(s, p, i, j + 2);
                bool p2 = (s[i] == p[j] || p[j] == '.') && f1(s, p, i + 1, j);
                return p1 || p2;
            }
        }
    }

    //记忆化搜索
    bool f2(string& s, string& p, int i, int j, auto& dp) {
        if (dp[i][j] != 0) return dp[i][j] == 1;
        bool ans;
        if (i == s.size()) {
            if (j == p.size()) ans = true;
            else {
                ans = j + 1 < p.size() && p[j + 1] == '*' && f2(s, p, i, j + 2, dp);
            }
        }
        else if (j == p.size()) ans = false;
        else {
            if (j + 1 == p.size() || p[j + 1] != '*') {
                ans = (s[i] == p[j] || p[j] == '.') && f2(s, p, i + 1, j + 1, dp);
            }
            else {
                bool p1 = f2(s, p, i, j + 2, dp);
                bool p2 = (s[i] == p[j] || p[j] == '.') && f2(s, p, i + 1, j, dp);
                ans = p1 || p2;
            }
        }
        dp[i][j] = ans ? 1 : 2;
        return ans;
    }

    //严格位置依赖的版本dp
    bool f3(string& s, string& p, auto& dp) {
        int n = s.size(), m = p.size();
        dp[n][m] = true;
        for (int j = m - 1; j >= 0; j--) {
            dp[n][j] = j + 1 < p.size() && p[j + 1] == '*' && dp[n][j + 2];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (j + 1 == p.size() || p[j + 1] != '*') {
                    dp[i][j] = (s[i] == p[j] || p[j] == '.') && dp[i + 1][j + 1];
                }else {
                    bool p1 = dp[i][j + 2];
                    bool p2 = (s[i] == p[j] || p[j] == '.') && dp[i + 1][j];
                    dp[i][j] = p1 || p2;
                }
            }
        }
        return dp[0][0];
    }
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        return f3(s, p, dp);
    }
};

int main() {
    return 0;
}