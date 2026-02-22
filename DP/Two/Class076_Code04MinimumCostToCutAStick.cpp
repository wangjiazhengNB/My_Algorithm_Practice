#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //记忆化搜索
    int minCost1(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<int> arr(m + 2);
        arr[0] = 0;
        sort(cuts.begin(), cuts.end());
        for (int i = 1; i <= m; i++) {
            arr[i] = cuts[i - 1];
        }
        arr[m + 1] = n;
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));
        return f1(arr, 1, m, dp);
    }
    int f1(vector<int>& arr, int l, int r, vector<vector<int>>& dp) {
        if (l > r) return 0;
        if (l == r) return arr[r + 1] - arr[l - 1];
        if (dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        for (int k = l; k <= r; k++) {
            ans = min(ans, f1(arr, l, k - 1, dp) + f1(arr, k + 1, r, dp));
        }
        ans += arr[r + 1] - arr[l - 1];
        dp[l][r] = ans;
        return ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<int> arr(m + 2);
        arr[0] = 0;
        sort(cuts.begin(), cuts.end());
        for (int i = 1; i <= m; i++) {
            arr[i] = cuts[i - 1];
        }
        arr[m + 1] = n;
        vector<vector<int>> dp(m + 2, vector<int>(m + 2));
        for (int i = 1; i <= m; i++) {
            dp[i][i] = arr[i + 1] - arr[i - 1];
        }
        for (int l = m - 1, next; l >= 1; l--) {
            for (int r = l + 1; r <= m; r++) {
                next = INT_MAX;
                for (int k = l; k <= r; k++) {
                    next = min(next, dp[l][k - 1] + dp[k + 1][r]);
                }
                dp[l][r] = next + arr[r + 1] - arr[l - 1];
            }
        }
        return dp[1][m];
    }
};

int main() {
    return 0;
}