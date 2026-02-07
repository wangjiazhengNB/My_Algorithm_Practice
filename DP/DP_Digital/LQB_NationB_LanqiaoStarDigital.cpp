#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 20;
ll dp[N][3][3][2];
// N : 数的位数
// pre[3] : 上一位 0 : 偶, 1 : 奇, 2 : 未填
// now[3] : 当前填了多少位min(now, w);
// free[2] : 0还不能随意取, 1可以随意取了
int n;

ll f(ll num, ll offset, int len, int pre, int now, int free) {
    if (len == 0) {
        if (now >= 2) return 1;
        else return 0; 
    }
    if (dp[len][pre][now][free] != -1) return dp[len][pre][now][free];
    ll ans = 0;
    int cur = num / offset % 10;
    if (free == 0) {
        if (pre == 2) {
            ans += f(num, offset / 10, len - 1, 2, 0, 1);
            for (int i = 1; i < cur; i++) {
                if (i % 2 == 0) ans += f(num, offset / 10, len - 1, 0, 1, 1);
                else ans += f(num, offset / 10, len - 1, 1, 1, 1);
            }
            if (cur % 2 == 0) ans += f(num, offset / 10, len - 1, 0, 1, 0);
            else ans += f(num, offset / 10, len - 1, 1, 1, 0);
        }
        else {
            for (int i = 0; i < cur; i++) {
                if (pre == 0 && i % 2 != 0) {
                    int new_now = min(now + 1, 2);
                    ans += f(num, offset / 10, len - 1, 1, new_now, 1);
                }  
                if (pre == 1 && i % 2 == 0) {
                    int new_now = min(now + 1, 2);
                    ans += f(num, offset / 10, len - 1, 0, new_now, 1);
                }
            }
            if (pre == 0 && cur % 2 != 0) {
                int new_now = min(now + 1, 2);
                ans += f(num, offset / 10, len - 1, 1, new_now, 0);
            }
            if (pre == 1 && cur % 2 == 0) {
                int new_now = min(now + 1, 2);
                ans += f(num, offset / 10, len - 1, 0, new_now, 0);
            }
        }
    }
    // free == 1, 数字随意取的情况
    else {
        if (pre == 2) {
            ans += f(num, offset / 10, len - 1, 2, , 1);
            for (int i = 1; i <= 9; i++) {
                if (i % 2 == 0) {
                    ans += f(num, offset / 10, len - 1, 0, 1, 1);
                }
                else {
                    ans += f(num, offset / 10, len - 1, 1, 1, 1);
                }
            }
        }
        else {
            for (int i = 0; i <= 9; i++) {
                if (pre == 0 && i % 2 != 0) {
                    int new_now = min(now + 1, 2);
                    ans += f(num, offset / 10, len - 1, 1, new_now, 1);
                }
                if (pre == 1 && i % 2 == 0) {
                    int new_now = min(now + 1, 2);
                    ans += f(num, offset / 10, len - 1, 0, new_now, 1);
                }
            }
        }
    }
    dp[len][pre][now][free] = ans;
    return ans;
}

// 计算 [1, m] 范围内的蓝桥星数字个数
ll cnt(ll m) {
    if (m < 10) return 0;
    int len = 1;
    ll offset = 1;
    ll temp = m / 10;
    while (temp > 0) {
        len++;
        offset *= 10;
        temp /= 10;
    }
    memset(dp, -1, sizeof dp);
    return f(m, offset, len, 2, 0, 0);
}

ll bs() {
    ll l = 10, r = 4e18, m;
    ll ans = -1;
    while (l <= r) {
        m = l + r >> 1;
        if (cnt(m) >= n) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    cout << bs() << '\n';
    return 0;
}