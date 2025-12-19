#include <bits/stdc++.h>
using namespace std;

const int N = 1005, mod = 19650827;
int n;
int arr[N];
int dp[N + 1][N + 1][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i + 1]) {
            dp[i][i + 1][0] = 1;
            dp[i][i + 1][1] = 1;
        }
    }
    for (int l = n - 2; l >= 0; l--) {
        for (int r = l + 2; r <= n; r++) {
            if (arr[l] < arr[l + 1]) {
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][0]) % mod;
            }
            if (arr[l] < arr[r]) {
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][1]) % mod;
            }
            if (arr[r] > arr[l]) {
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][0]) % mod;
            }
            if (arr[r] > arr[r - 1]) {
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][1]) % mod;
            }
        }
    }
    cout << (dp[1][n][0] + dp[1][n][1]) % mod;
    return 0;
}