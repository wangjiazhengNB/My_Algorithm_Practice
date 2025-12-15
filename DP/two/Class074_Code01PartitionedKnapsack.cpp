#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
int dp[N][N];
struct Node {
    int a, b, c;
    bool operator<(const Node& C)const {
        return c < C.c;
    }
}arr[N];

//严格位置依赖版的
int compute1() {
    int teams = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i - 1].c != arr[i].c) {
            teams++;
        }
    }
    for (int start = 1, end = 2, i = 1; start <= n; i++) {
        while (end <= n && arr[end].c == arr[start].c) {
            end++;
        }
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = start; k < end; k++) {
                if (j >= arr[k].a) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[k].a] + arr[k].b);
                }
            }
        }
        start = end++;
    }
    return dp[teams][m];
}

//空间压缩
int compute2() {
    vector<int> dp(m + 1, 0);
    for (int start = 1, end = 2, i = 1; start <= n; i++) {
        while (end <= n && arr[start].c == arr[end].c) end++;
        for (int j = m; j >= 0; j--) {
            for (int k = start; k < end; k++) {
                if (j >= arr[k].a) dp[j] = max(dp[j], dp[j - arr[k].a] + arr[k].b);
            }
        }
        start = end++;
    }
    return dp[m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }
    sort(arr + 1, arr + n + 1);
    cout << compute2();
    return 0;
}