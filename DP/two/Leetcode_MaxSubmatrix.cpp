#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> nums(m);
        int maxn = INT_MIN;
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        for (int up = 0; up < n; up++) {
            nums.assign(m, 0);
            for (int down = up; down < n; down++) {
                for (int l = 0, r = 0, pre = INT_MIN; r < m; r++) {
                    nums[r] += matrix[down][r];
                    if (pre >= 0) {
                        pre += nums[r];
                    }
                    else {
                        pre = nums[r];
                        l = r;
                    }
                    if (pre > maxn) {
                        maxn = pre;
                        x1 = up;
                        y1 = l;
                        x2 = down;
                        y2 = r;
                    }
                }
            }
        }
        return {x1, y1, x2, y2};
    }
};

int main() {
    return 0;
}