#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int nums[N];
int dp[N];
int n;

int minCost() {
    sort(nums, nums + n);
    if (n >= 1) {
        dp[0] = nums[0];
    }
    if (n >= 2) {
        dp[1] = nums[1];
    }
    if (n >= 3) {
        dp[2] = nums[0] + nums[1] + nums[2];
    }
    for (int i = 3; i < n; i++) {
        dp[i] = min(dp[i - 1] + nums[i] + nums[0], dp[i - 2] + nums[1] + nums[1] + nums[i] + nums[0]);
    }
    return dp[n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << minCost();
    }
    return 0;
}