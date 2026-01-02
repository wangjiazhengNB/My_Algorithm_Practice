#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int mod = 0;
        for (int num : nums) {
            mod = (mod + num) % p;
        }
        if (mod == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        int ans = INT_MAX;
        for (int i = 0, cur = 0, find; i < nums.size(); i++) {
            cur = (cur + nums[i]) % p;
            find = (cur + p - mod) % p;
            if (mp.count(find)) {
                ans = min(ans, i - mp[find]);
            }
            mp[cur] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};