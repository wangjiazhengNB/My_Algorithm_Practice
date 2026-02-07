#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

string s;
int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    n = s.size();
    if (n < 2) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1] || s[i] == '?' || s[i - 1] == '?') {
            ans++;
            i++;
        }
    }
    cout << ans << '\n';
    return 0;
}