#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// 暴力递归（用于测试）
int f1(int rest, int k) {
    if (k == 1) {
        return rest;
    }
    int ans = INT_MIN;
    for (int cur = 1; cur <= rest && (rest - cur) >= (k - 1); ++cur) {
        int curAns = cur * f1(rest - cur, k - 1);
        ans = max(ans, curAns);
    }
    return ans;
}


int maxValue1(int n, int k) {
    return f1(n, k);
}

// 快速幂：
long long power(long long x, int n, int mod) {
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

// 贪心解法：
int maxValue2(int n, int k) {
    long long a = n / k;
    int b = n % k;
    long long part1 = power(a + 1, b, MOD);
    long long part2 = power(a, k - b, MOD);
    return (int)((part1 * part2) % MOD);
}

// 对数器：
int main() {
   
    srand((unsigned int)time(0));
    
    const int N = 30;
    int testTimes = 2000;
    cout << "测试开始" << endl;
    
    for (int i = 1; i <= testTimes; ++i) {
        int n = (rand() % N) + 1;
       
        int k = (rand() % n) + 1;
        
        int ans1 = maxValue1(n, k);
        int ans2 = maxValue2(n, k);
        
        if (ans1 != ans2) {
            cout << "出错了！" << endl;
           
            cout << "n = " << n << ", k = " << k << endl;
            cout << "ans1 = " << ans1 << ", ans2 = " << ans2 << endl;
        }
        
        if (i % 100 == 0) {
            cout << "测试到第" << i << "组" << endl;
        }
    }
    
    cout << "测试结束" << endl;
    return 0;
}