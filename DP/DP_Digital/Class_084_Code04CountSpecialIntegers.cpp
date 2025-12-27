#include <bits/stdc++.h>
using namespace std;

int num;
int cnt[15];

int f(int len, int offset, int status) {
    if (len == 0) return 1;
    int ans = 0;
    int first = (num / offset) % 10;
    for (int cur = 0; cur < first; cur++) {
        if (((1 << cur) & status) == 0) {
            ans += cnt[len - 1];
        }
    }
    if ((status & (1 << first)) == 0) {
        ans += f(len - 1, offset / 10, status | (1 << first));
    }
    return ans;
}

int countSpecialNumbers(int n) {
    int ans = 0;
    int len = 1;
    num = n;
    int tmp = n / 10;
    int offset = 1;
    while (tmp > 0) {
        tmp /= 10;
        offset *= 10;
        len++;
    } 
    if (len >= 2) {
        ans = 9;
        for (int i = 2, a = 9, b = 9; i < len; i++, b--) {
            a *= b;
            ans += a;
        }
    }
    memset(cnt, 0, sizeof cnt);
    cnt[0] = 1;
    for (int i = 1, k = 10 - len + 1; i < len; i++, k++) {
        cnt[i] = cnt[i - 1] * k;
    }
    int first = num / offset;
    ans += (first - 1) * cnt[len - 1];
    ans += f(len - 1, offset / 10, 1 << first);
    return ans;
}


class Solution {
public:
    int countSpecialNumbers(int n) {
        return ::countSpecialNumbers(n);
    }
};

int main() {
    return 0;
}