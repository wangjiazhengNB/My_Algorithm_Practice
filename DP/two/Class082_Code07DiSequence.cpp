#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int numPermsDISequence1(string s) {
       return f1(s, 0, s.size() + 1, s.size() + 1);
    }
    //暴力尝试递归，超时
    int f1(string& s, int i, int less, int n) {
        int ans = 0;
        if (i == n) {
            ans = 1;
        }
        else if (i == 0 || s[i - 1] == 'D') {
            for (int nextLess = 0; nextLess < less; nextLess++) {
                ans += f1(s, i + 1, nextLess, n);
            }
        }
        else {
            for (int nextLess = less, k = 1; k <= n - i - less; k++, nextLess++) {
                ans += f1(s, i + 1, nextLess, n);
            }
        }
        return ans;
    }

    //严格位置依赖的dp
    int numPermsDISequence2(string s) {
        int n = s.size() + 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int less = 0; less <= n; less++) {
            dp[n][less] = 1;
        } 
        for (int i = n - 1; i >= 0; i--) {
            for (int less = 0; less <= n; less++) {
                if (i == 0 || s[i - 1] == 'D') {
                    for (int nextLess = 0; nextLess < less; nextLess++) {
                        dp[i][less] = (dp[i][less] + dp[i + 1][nextLess]) % mod;
                    }
                }
                else {
                    for (int nextLess = less, k = 1; k <= n - i - less; k++, nextLess++) {
                        dp[i][less] = (dp[i][less] + dp[i + 1][nextLess]) % mod;
                    }
                }
            }
        }
        return dp[0][n];  
    }

    //通过观察法，得到优化枚举的方法
    int numPermsDISequence(string s) {
        int n = s.size() + 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int less = 0; less <= n; less++) {
            dp[n][less] = 1;
        } 
        for (int i = n - 1; i >= 0; i--) {
            if (i == 0 || s[i - 1] == 'D') {
                dp[i][1] = dp[i + 1][0];
                for (int less = 2; less <= n; less++) {
                    dp[i][less] = (dp[i][less - 1] + dp[i + 1][less - 1]) % mod;
                }
            }
            else {
                dp[i][n - i - 1] = dp[i + 1][n - i - 1];
                for (int less = n - i - 2; less >= 0; less--) {
                    dp[i][less] = (dp[i][less + 1] + dp[i + 1][less]) % mod;
                }
            }
        }
        return dp[0][n];  
    }
};

int main() {
    return 0;
}