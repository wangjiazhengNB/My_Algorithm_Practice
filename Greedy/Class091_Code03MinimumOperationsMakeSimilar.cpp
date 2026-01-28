#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int odds = split(nums, n);
        int oddss = split(target, n);
        sort(nums.begin(), nums.begin() + odds);
        sort(nums.begin() + odds, nums.end());
        sort(target.begin(), target.begin() + odds);
        sort(target.begin() + odds, target.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs((long long)target[i] - nums[i]);
        }
        return ans / 4;
    }
    int split(vector<int>& arr, int n) {
        int odds = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                swap(arr, i, odds++);
            }
        }
        return odds;
    }
    void swap(vector<int>& arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

int main() {
    return 0;
}