#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    int brk = 0;
    ll ans = 0;
    for (int l = 0, r = 0; r < s.size(); r++) {
        if (r && s[r - 1] + 1 != s[r] && s[r - 1] != s[r]) {
            brk++;
        }
        while (brk > 1) {
            l++;
            if (s[l] != s[l - 1] && s[l] != s[l - 1] + 1) brk--;
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';
    return 0;
}