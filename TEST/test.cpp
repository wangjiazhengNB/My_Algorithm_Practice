#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005, mod = 1e9 + 7;
ll T, n, sum, arr[N], dp[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % 2 != 0) {
            cout << 0 << '\n';
            continue;
        }
        cout << 0 << '\n';
    }
    return 0;
}