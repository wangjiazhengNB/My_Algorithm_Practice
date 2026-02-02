#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
double dp[N][2];
int a[N], b[N], x[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    dp[0][0] = 0;
    dp[1][0] = x[1], dp[1][1] = x[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + x[i] - x[i - 1], dp[i - 1][1] + x[i] - x[i - 1]);
        double last;
        if (a[i - 1] > b[i - 2]) last = (a[i - 1] - b[i - 2]) / 0.7;
        else last = (b[i - 2] - a[i - 1]) / 1.3;
        dp[i][1] = min(dp[i - 1][0] + a[i - 1] / 0.7 + b[i - 1] / 1.3, dp[i - 1][1] - b[i - 2] / 1.3 + last + b[i - 1] / 1.3);
    }
    printf("%.2lf", min(dp[n][0], dp[n][1]));
    return 0;
}