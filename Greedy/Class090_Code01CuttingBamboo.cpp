#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len == 2) return 1;
        if (bamboo_len == 3) return 2;
        int tail = bamboo_len % 3 == 0 ? 1 : (bamboo_len % 3 == 1 ? 4 : 2);
        int power = (tail == 1 ? bamboo_len : (bamboo_len - tail)) / 3;
        long long ans = (qmi(3, power) * tail) % mod;
        return ans;
    }
    long long qmi(long long x, int n) {
        long long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;
        }
        return ans;
    }

};

int main() {
    return 0;
}