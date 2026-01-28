#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int next = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (cur < i) {
                ans++;
                cur = next;
            }
            next = max(next, i + nums[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}