#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int N = 30005;
int stack_[N];
int r;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        memset(stack_, 0, sizeof stack_);
        r = 0;
        ll ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (r > 0 && arr[stack_[r - 1]] >= arr[i]) {
                int cur = stack_[--r];
                int left = r == 0 ? -1 : stack_[r - 1];
                ans = (ans + (ll)(cur - left) * (i - cur) * arr[cur]) % mod;
            }
            stack_[r++] = i;
        }
        while (r > 0) {
            int cur = stack_[--r];
            int left = r == 0 ? -1 : stack_[r - 1];
            ans = (ans + (ll)(cur - left) * (arr.size() - cur) * arr[cur]) % mod;
        }
        return (int)ans;
    }
};

int main() {
    return 0;
}