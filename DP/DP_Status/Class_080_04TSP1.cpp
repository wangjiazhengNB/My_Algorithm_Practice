#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int graph[N][N];
int dp[1 << N][N];
int n;

int compute(int s, int i) {
    if (s == (1 << n) - 1) {
        return graph[i][0];
    }
    if (dp[s][i] != -1) return dp[s][i];
    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        if ((s & (1 << j)) == 0) {
            ans = min(ans, graph[i][j] + compute(s | (1 << j), j));
        }
    }
    dp[s][i] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0, c; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            graph[i][j] = c;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << compute(1, 0);
    return 0;
}