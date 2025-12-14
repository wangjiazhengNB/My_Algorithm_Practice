#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int N = 100005;
    static int nums[N];
    static int ends[N];
    static int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0, size; i < k; i++) {
            size = 0;
            for (int j = i; j < n; j += k) {
                nums[size++] = arr[j];
            }
            ans += size - lengthOfNoDecreasing(size);
        }
        return ans;
    }
    static int lengthOfNoDecreasing(int n) {
        int len = 0;
        for (int i = 0; i < n; i++) {
            int find = bs(nums[i], len);
            if (find == -1) {
                ends[len++] = nums[i];
            }
            else {
                ends[find] = nums[i];
            }
        }
        return len;
    }
    static int bs(int num, int len) {
        int l = 0, r = len - 1, mid, ans = -1;
        while (l <= r) {
            mid = l + r >> 1;
            if (ends[mid] > num) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int Solution::nums[Solution::N] = {0};
int Solution::ends[Solution::N] = {0};

int main() {
    return 0;
}