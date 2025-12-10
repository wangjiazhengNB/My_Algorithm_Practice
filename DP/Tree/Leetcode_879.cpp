#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    // n : 员工的额度，不能超
    // p : 利润的额度，不能少
    // group[i] : i号项目需要几个人
    // profit[i] : i号项目产生的利润
    // 返回能做到员工不能超过n，利润不能少于p的计划有多少个
    int f(vector<int>& group, vector<int>& profit, int i, int r, int s, auto& dp) {
        if (r <= 0) {
            return s == 0 ? 1 : 0;
        }
        if (i == group.size()) {
            return s == 0 ? 1 : 0;
        }
        if (dp[i][r][s] != -1) return dp[i][r][s];
        int p1 = f(group, profit, i + 1, r, s, dp);
        int p2 = 0;
        if (group[i] <= r) {
            p2 = f(group, profit, i + 1, r - group[i], max(s - profit[i], 0), dp);
        }
        int ans = (p1 + p2) % mod;
        dp[i][r][s] = ans;
        return ans;
    } 
    int profitableSchemes1(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

        return f(group, profit, 0, n, minProfit, dp) % mod;
    }

    int profitableSchemes2(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (int r = 0; r <= n; r++) {
            dp[r][0] = 1;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int r = n; r >= 0; r--) {
                for (int s = minProfit; s >= 0; s--) {
                    int p1 = dp[r][s];
                    int p2 = r >= group[i] ? dp[r - group[i]][max(0, s - profit[i])] : 0;
                    dp[r][s] = (p1 + p2) % mod;
                }
            }
        }
        return dp[n][minProfit];
    }
};

int main() {
    return ;
}