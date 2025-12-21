#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int numberWays(vector<vector<int>>& arr) {
        int m = 0;
        for (vector<int> person : arr) {
            for (int hat : person) {
                m = max(hat, m);
            }
        }
        int n = arr.size();
        vector<int> hats(m + 1);
        for (int pi = 0; pi < n; pi++) {
            for (int hat : arr[pi]) {
                hats[hat] |= 1 << pi;
            }
        }
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
        return f(hats, m, n, 1, 0, dp);
    }
    int f(vector<int>& hats, int m, int n, int i, int s, vector<vector<int>>& dp) {
        if (s == (1 << n) - 1) {
            return 1;
        }
        if (i == m + 1) {
            return 0;
        }
        if (dp[i][s] != -1) return dp[i][s];
        int ans = f(hats, m, n, i + 1, s, dp);
        int cur = hats[i];
        int rightOne;
        while (cur != 0) {
            rightOne = cur & -cur;
            if ((s & rightOne) == 0) {
                ans = (ans + f(hats, m, n, i + 1, s | rightOne, dp)) % mod;
            }
            cur = cur ^ rightOne;
        }
        dp[i][s] = ans;
        return ans;
    }
};