#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int numberOfPaths1(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return f(grid, n, m, k, 0, 0, 0, dp);
    }
    int f(vector<vector<int>>& grid, int n, int m, int k, int i, int j, int r, vector<vector<vector<int>>>& dp) {
        if (i == n - 1 && j == m - 1) {
            return grid[i][j] % k == r ? 1 : 0;
        }
        if (dp[i][j][r] != -1) return dp[i][j][k];
        int ans = 0;
        int need = (k + r - grid[i][j] % k) % k;
        if (i + 1 < n) {
            ans = f(grid, n, m, k, i + 1, j, need, dp);
        }
        if (j + 1 < m) {
            ans += (f(grid, n, m, k, i, j + 1, need, dp)) % mod;
        }
        dp[i][j][k] = ans;
        return ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));
        dp[n - 1][m - 1][grid[n - 1][m - 1] % k] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int r = 0; r < k; r++) {
                int need = (k + r - grid[i][m - 1] % k) % k;
                dp[i][m - 1][r] = dp[i + 1][m - 1][need];
            }
        }
        for (int j = m - 2; j >= 0; j--) {
            for (int r = 0; r < k; r++) {
                int need = (k + r - grid[n - 1][j] % k) % k;
                dp[n - 1][j][r] = dp[n - 1][j + 1][need];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                for (int r = 0; r < k; r++) {
                    int need = (k + r - grid[i][j] % k) % k;
                    dp[i][j][r] = (dp[i + 1][j][need] + dp[i][j + 1][need]) % mod;
                }
            }
        }
        return dp[0][0][0];
    }
};

int main() {
    return 0;
}