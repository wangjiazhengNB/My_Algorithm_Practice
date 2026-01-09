#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int num, vector<int>& arr) {
        int maxn = 0;
        long long sum = 0;
        for (int x : arr) {
            maxn = max(maxn, x);
            sum += x;
        }
        if (sum > (long long)maxn * num) {
            return sum / num;
        }
        int ans = 0;
        for (int l = 0, r = maxn, m; l <= r;) {
            m = l + ((r - l) >> 1);
            if (f(arr, num, m)) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;
    }

    bool f(vector<int>& arr, int num, int time) {
        long long sum = 0;
        for (int x : arr) {
            if (x > time) {
                num--;
            }
            else {
                sum += x;
            }
            if (sum >= (long long) num * time) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return;
}