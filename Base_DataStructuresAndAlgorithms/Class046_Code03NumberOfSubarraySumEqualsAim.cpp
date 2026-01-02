#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.count(sum - k)) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};