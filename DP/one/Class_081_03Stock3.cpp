#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //没有优化枚举的方法
    //会超时
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n), dp2(n);
        int mins = prices[0];
        for (int i = 1; i < n; i++) {
            mins = min(mins, prices[i]);
            dp1[i] = max(dp1[i - 1], prices[i] - mins);
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp2[i] = max(dp2[i], dp1[j] + prices[i] - prices[j]);
            }
            ans = max(ans, dp2[i]);
        }
        return ans;
    }

    //观察出优化枚举的方法
    //引入best数组，需要分析能力
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n), dp2(n);
        int mins = prices[0];
        for (int i = 1; i < n; i++) {
            mins = min(mins, prices[i]);
            dp1[i] = max(dp1[i - 1], prices[i] - mins);
        }
        vector<int> best(n);
        best[0] = dp1[0] - prices[0];
        for (int i = 1; i < n; i++) {
            best[i] = max(best[i - 1], dp1[i] - prices[i]);
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            dp2[i] = best[i] + prices[i];
            ans = max(ans, dp2[i]);
        }
        return ans;
    }
    //最优版本，空间压缩到极致，for循环写到一起
     int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp1 = 0, dp2, best = -prices[0];
        int mins = prices[0], ans = 0;
        for (int i = 1; i < n; i++) {
            mins = min(mins, prices[i]);
            dp1 = max(dp1, prices[i] - mins);
            best = max(best, dp1 - prices[i]);
            dp2 = best + prices[i];
            ans = max(ans, dp2);
        }
        return ans;
    }
};

int main() {
    return 0;
}