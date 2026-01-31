#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        string s;
        cin >> n;
        cin >> s;
        int cnt = 0;
        s = '1' + s + '1';
        for (int i = 1, l = 1; i <= n; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1') {
                    l = i;
                }
                if (s[i + 1] == '1') {
                    int c = (l == 1) + (i == n);
                    cnt += (i - l + c + 1) / 3;
                }
            }
            else {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}