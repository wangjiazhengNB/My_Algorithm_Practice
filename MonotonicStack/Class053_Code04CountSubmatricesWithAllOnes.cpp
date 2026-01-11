#include <bits/stdc++.h>
using namespace std;

const int M =151;

int height[M];
int stack_[M];
int r;


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        memset(height, 0, sizeof height);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                height[j] = mat[i][j] == 0 ? 0 : height[j] + 1;
            }
            ans += compute(m);
        }
        return ans;
    }
    int compute(int m) {
        r = 0;
        int ans = 0;
        for (int i = 0, left, len, bottom; i < m; i++) {
            while (r > 0 && height[stack_[r - 1]] >= height[i]) {
                int cur = stack_[--r];
                if (height[cur] > height[i]) {
                    left = r == 0 ? -1 : stack_[r - 1];
                    len = i - left - 1;
                    bottom = max(left == -1 ? 0 : height[left], height[i]);
                    ans += (height[cur] - bottom) * len * (len + 1) / 2;
                }
            }
            stack_[r++] = i;
        }
        while (r > 0) {
            int cur = stack_[--r];
            int left = r == 0 ? -1 : stack_[r - 1];
            int len = m - left - 1;
            int down = left == -1 ? 0 : height[left];
            ans += (height[cur] - down) * len * (len + 1) / 2;
        }
        return ans;
    }
};

int main() {
    return 0;
}