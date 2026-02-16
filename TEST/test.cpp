#include <bits/stdc++.h>
using namespace std;

void factorize(int n) {
    bool first = true; // 标记是否是第一个质因数，用于控制乘号的打印
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0; // 统计指数
            // 只要还能被 i 整除，就一直除，统计次数
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            // 打印部分
            if (!first) {
                printf(" * "); // 如果不是第一个，前面加乘号
            }
            printf("%d^%d", i, cnt);
            first = false; // 第一个已经打印过了
        }
    }
    // 关键：处理最后剩下的那个质数（如果 n > 1，说明它本身是个质数）
    if (n > 1) {
        if (!first) {
            printf(" * ");
        }
        printf("%d^1", n);
    }
    printf("\n");
}

int main() {
    factorize(2025);
    factorize(1260); // 多测试一个例子
    return 0;
}