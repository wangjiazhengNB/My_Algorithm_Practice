#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int stack_[N];
int r;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        init();
        vector<int> ans(n);
        for (int i = 0, cur; i < n; i++) {
            while (r > 0 && arr[stack_[r - 1]] < arr[i]) {
                cur = stack_[--r];
                ans[cur] = i - cur;
            }
            stack_[r++] = i;
        }
        return ans;
    }
    void init() {
        memset(stack_, 0, sizeof stack_);
        r = 0;
    }
};

int main() {
    return 0;
}