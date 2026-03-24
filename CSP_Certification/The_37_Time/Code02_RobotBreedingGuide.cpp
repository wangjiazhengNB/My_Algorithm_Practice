#include <iostream>
#include <cstring>
using namespace std;

const int N = 10005, M = 105;
int n, m;
int arr[M];
int dp[N];

int f(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= m) {
            ans = max(ans, arr[i] + f(n - i));
        }
    }
    dp[n] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
    }
    cout << f(n) << endl;
    return 0;
}