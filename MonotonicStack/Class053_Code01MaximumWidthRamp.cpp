#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int stack_[N];
int r;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        r = 1;
        for (int i = 1; i < n; i++) {
            while (r > 0 && nums[stack_[r - 1]] > nums[i]) {
                stack_[r++] = i;
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (r > 0 && nums[stack_[r - 1]] <= nums[i]) {
                ans = max(ans, i - stack_[--r]);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}