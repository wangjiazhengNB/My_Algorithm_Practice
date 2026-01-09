#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int heigh[N];
int stack_[N];
int r;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(heigh, 0, sizeof heigh);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heigh[j] = grid[i][j] == '0' ? 0 : heigh[j] + 1;
            }
            ans = max(ans, f(m));
        }
        return ans;
    }
    int f(int m) {
        r = 0;
        int ans = 0, cur, left;
        for (int i = 0; i < m; i++) {
            while (r > 0 && heigh[stack_[r - 1]] >= heigh[i]) {
                cur = stack_[--r];
                left = r == 0 ? -1 : stack_[r - 1];
                ans = max(ans, heigh[cur] * (i - left - 1));
            }
            stack_[r++] = i;
        }
        while (r > 0) {
            cur = stack_[--r];
            left = r == 0 ? -1 : stack_[r - 1];
            ans = max(ans, heigh[cur] * (m - left - 1));
        }
        return ans;
    }
};

int main() {
    return 0;
}