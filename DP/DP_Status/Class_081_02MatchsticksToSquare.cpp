#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for (int t : matchsticks) {
            sum += t;
        }
        if (sum % 4 != 0) return false;
        vector<int> dp(1 << n);
        return f(matchsticks, sum / 4, (1 << n) - 1, 0, 4, dp);
    }
    bool f(vector<int>& nums, int limit, int status, int cur, int rest, vector<int>& dp) {
        if (rest == 0) {
            return status == 0;
        }
        if (dp[status] != 0) return dp[status] == 1;
        bool ans = false;
        for (int i = 0; i < nums.size(); i++) {
            if ((status & (1 << i)) != 0 && cur + nums[i] <= limit) {
                if (cur + nums[i] == limit) {
                    ans = f(nums, limit, status ^ (1 << i), 0, rest - 1, dp);
                }
                else {
                    ans = f(nums, limit, status ^ (1 << i), cur + nums[i], rest, dp);
                }
                if (ans) break;
            }
        }
        dp[status] = ans ? 1 : -1;
        return ans;
    }
};

int main() {
    return 0;
}