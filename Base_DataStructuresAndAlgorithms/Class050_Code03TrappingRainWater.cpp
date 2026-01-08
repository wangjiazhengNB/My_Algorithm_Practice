#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //辅助函数写法
    //时间复杂度O(n), 空间复杂度O(n)不是最优
    int trap1(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n);
        vector<int> rmax(n);
        lmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], height[i]);
        }
        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans += max(0, min(lmax[i - 1], rmax[i + 1]) - height[i]);
        }
        return ans;
    }

    //双指针写法
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0], rmax = height[n - 1];
        int l = 1, r = n - 2;
        int ans = 0;
        while (l <= r) {
            if (lmax < rmax) {
                ans += max(0, lmax - height[l]);
                lmax = max(lmax, height[l++]);
            }
            else {
                ans += max(0, rmax - height[r]);
                rmax = max(rmax, height[r--]);
            }
        }
        return ans;
    }
};