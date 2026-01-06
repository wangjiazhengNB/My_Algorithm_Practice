#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        for (int l = 0, r = 0, sum = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum - nums[l] >= target) {
                sum -= nums[l++];
            }
            if (sum >= target) ans = min(ans, r - l + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    return 0;
}