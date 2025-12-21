#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canIWin(int n, int m) {
        if (m == 0) {
            return true;
        }
        if (n * (n + 1) / 2 < m) {
            return false;
        }
        vector<int> dp(1 << (n + 1));
        return f(n, (1 << (n + 1)) - 1, m, dp);
    }
    bool f(int n, int status, int rest, vector<int>& dp) {
        if (rest <= 0) {
            return false;
        }
        if (dp[status] != 0) return dp[status] == 1;
        bool ans = false;
        for (int i = 1; i <= n; i++) {
            if ((status & (1 << i)) != 0 && !f(n, status ^ (1 << i), rest - i, dp)) {
                ans = true;
                break;
            }
        }
        dp[status] = ans ? 1 : -1;
        return ans;
    } 
};


int main() {
    return 0;
}