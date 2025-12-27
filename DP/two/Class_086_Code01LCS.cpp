#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int dp[N][N];
char ans[N];
int n, m, k;

int dpFunc(string& s1, string& s2) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}


void lcs(string& s1, string &s2) {
    if (k > 0) {
        for (int len = k, i = n, j = m; len > 0;) {
            if (s1[i - 1] == s2[j - 1]) {
                ans[--len] = s1[i - 1];
                i--;
                j--;
            }
            else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
    }
}




int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    //memset(dp, 0, sizeof dp);
    n = s1.size(), m = s2.size();
    k = dpFunc(s1, s2);
    lcs(s1, s2);
    if (k == 0) {
        cout << -1 << endl;
    }
    else {
        for (int i = 0; i < k; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
