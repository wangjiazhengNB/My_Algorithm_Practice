#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 0, m, ans = 0; // 改为long long
        for (int pile : piles) {
            r = max(r, (long long)pile);
        }
        while (l <= r) {
            m = (l + r) >> 1; // 此时l + r不会溢出，因为是long long
            if (f(piles, m) <= h) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return (int)ans;
    }

    long long f(vector<int>& piles, long long m) { // 返回值改为long long
        long long t = 0; // 改为long long
        for (int pile : piles) {
            t += (pile + m - 1) / m;
        }
        return t;
    }
};

int main() {
    return 0;
}