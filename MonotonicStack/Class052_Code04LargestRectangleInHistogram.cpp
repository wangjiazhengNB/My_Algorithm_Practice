#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int stack_[N];
int r;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        memset(stack_, 0, sizeof stack_);
        r = 0;
        int ans = 0, cur, left;
        for (int i = 0; i < n; i++) {
            while (r > 0 && heights[stack_[r - 1]] >= heights[i]) {
                cur = stack_[--r];
                left = r == 0 ? -1 : stack_[r - 1];
                ans = max(ans, heights[cur] * (i - left - 1));
            }
            stack_[r++] = i;
        }
        while (r > 0) {
            cur = stack_[--r];
            left = r == 0 ? -1 : stack_[r - 1];
            ans = max(ans, heights[cur] * (n - left - 1));
        }
        return ans;
    }
};

int main() {
    return 0;
}