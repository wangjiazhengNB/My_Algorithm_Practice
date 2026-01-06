#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid1, int stamph, int stampw) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> grid(n + 2, vector<int>(m + 2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                grid[i][j] = grid1[i - 1][j - 1];
            }
        }
        vector<vector<int>> sum(n + 2, vector<int>(m + 2));
        vector<vector<int>> diffarr(n + 2, vector<int>(m + 2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i][j];
            }
        }
        for (int a = 1, c = a + stamph - 1; c <= n; a++, c++) {
            for (int b = 1, d = b + stampw - 1; d <= m; b++, d++) {
                if (getsum(a, b, c, d, sum) == 0) {
                    getdiff(a, b, c, d, diffarr);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                diffarr[i][j] += diffarr[i - 1][j] + diffarr[i][j - 1] - diffarr[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j] == 0 && diffarr[i][j] == 0) return false;
            }
        }
        return true;
    }
    int getsum(int a, int b, int c, int d, vector<vector<int>>& sum) {
        int ans = 0;
        ans = sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
        return ans;
    }
    void getdiff(int a, int b, int c, int d, vector<vector<int>>& diffarr) {
        diffarr[a][b] += 1;
        diffarr[c + 1][b] -= 1;
        diffarr[a][d + 1] -= 1;
        diffarr[c + 1][d + 1] += 1;
    }
};

int main() {
    return 0;
}