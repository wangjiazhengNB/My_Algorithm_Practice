#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
        return f(boxes, 0, n - 1, 0, dp);
    }
    int f(vector<int>& boxes, int l, int r, int k, auto& dp) {
        if (l > r) return 0;
        if (dp[l][r][k] > 0) return dp[l][r][k];
        int s = l;
        while (s + 1 <= r && boxes[l] == boxes[s + 1]) {
            s++;
        }
        int cnt = k + s - l + 1;
        int ans = cnt * cnt + f(boxes, s + 1, r, 0, dp);
        for (int m = s + 2; m <= r; m++) {
            if (boxes[l] == boxes[m] && boxes[m - 1] != boxes[m]) {
                ans = max(ans, f(boxes, s + 1, m - 1, 0, dp) + f(boxes, m, r, cnt, dp));
            }
        }
        dp[l][r][k] = ans;
        return ans;
    }
};

int main() {
    return 0;
}