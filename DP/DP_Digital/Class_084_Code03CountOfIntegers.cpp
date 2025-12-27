#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 23, M = 405;
int min_num, max_num, len;
int dp[N][M][2];
string num;

int f(int i, int sum, int free);
bool check();

void build() {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= max_num; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
}


int count(string num1, string num2, int min_sum, int max_sum) {
    min_num = min_sum;
    max_num = max_sum;
    int len1 = num1.size();
    int len2 = num2.size();
    num = num2;
    len = len2;
    build();
    int ans = f(0, 0, 0) % mod;
    num = num1;
    len = len1;
    build();
    ans = (ans - f(0, 0, 0) + mod) % mod;
    if (check()) {
        ans = (ans + 1) % mod;
    }
    return ans;
}

int f(int i, int sum, int free) {
    if (sum > max_num) return 0;
    if (sum + (len - i) * 9 < min_num) return 0;
    if (i == len) return 1;
    if (dp[i][sum][free] != -1) return dp[i][sum][free];
    int cur = num[i] - '0';
    int ans = 0;
    if (free == 0) {
        for (int k = 0; k < cur; k++) {
            ans = (ans + f(i + 1, sum + k, 1)) % mod;
        } 
        ans = (ans + f(i + 1, sum + cur, 0)) % mod;
    }
    else {
        for (int k = 0; k <= 9; k++) {
            ans = (ans + f(i + 1, sum + k, 1)) % mod;
        }
    }
    dp[i][sum][free] = ans;
    return ans;
}

bool check() {
    int sum = 0;
    for (int i = 0; i < num.size(); i++) {
        sum += num[i] - '0';
    }
    return sum >= min_num && sum <= max_num;
}


class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        return ::count(num1, num2, min_sum, max_sum);
    }
};

int main() {
    return 0;
}