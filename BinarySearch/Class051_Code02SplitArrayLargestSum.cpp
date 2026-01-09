#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        ll l = 0, r, m, ans = 0;
        for (int num : nums) {
            r += num;
        }
        while (l <= r) {
            m = (l + r) >> 1;
            if (f(nums, m) <= k) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
    int f(vector<int>& nums, int m) {
        int k = 1, sum = 0;
        for (int num : nums) {
            if (num > m) {
                return INT_MAX;
            }
            else {
                sum += num;
                if (sum > m) {
                    k++;
                    sum = num;
                }
            }
        }
        return k;
    }
};

int main() {
    return 0;
}