#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countEval(string s, int result) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        vector<int> ft = f(s, 0, n - 1, dp);
        return ft[result];
    } 
    vector<int> f(string s, int l, int r, auto& dp) {
        if (!dp[l][r].empty()) return dp[l][r];
        int f_cnt = 0;
        int t_cnt = 0;
        if (l == r) {
            f_cnt = (s[l] == '0') ? 1 : 0;
            t_cnt = (s[l] == '1') ? 1 : 0;
        }
        else {
            vector<int> tmp;
            for (int k = l + 1, a, b, c, d; k <= r - 1; k += 2) {
                tmp = f(s, l, k - 1, dp);
                a = tmp[0];
                b = tmp[1];
                tmp = f(s, k + 1, r, dp);
                c = tmp[0];
                d = tmp[1];
                if (s[k] == '&') {
                    f_cnt += a * c + a * d + b * c;
                    t_cnt += b * d;
                }
                else if (s[k] == '|') {
                    f_cnt += a * c;
                    t_cnt += b * c + b * d + a * d;
                }
                else {
                    f_cnt += a * c + b * d;
                    t_cnt += a * d + b * c;
                }
            }
        }
        vector<int> ft = {f_cnt, t_cnt};
        dp[l][r] = ft;
        return ft;
    }
};

int main() {
    return 0;
}