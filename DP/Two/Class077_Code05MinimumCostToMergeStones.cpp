#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> presum(n + 1);
        for (int i = 0, j = 1, sum = 0; i < n; i++, j++) {
            sum += stones[i];
            presum[j] = sum;
        }
        for (int l = n - 2; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {
                int ans = INT_MAX;
                for (int m = l; m < r; m += k - 1) {
                    ans = min(ans, dp[l][m] + dp[m + 1][r]);
                }
                if ((r - l) % (k - 1) == 0) {
                    ans += presum[r + 1] - presum[l];
                }
                dp[l][r] = ans;
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    return 0;
}