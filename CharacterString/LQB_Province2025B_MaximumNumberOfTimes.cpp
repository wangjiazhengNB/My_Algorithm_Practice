#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    if (n < 3) {
        cout << 0 << '\n';
        return 0;
    }
    int l = 0, r = 2;
    int ans = 0;
    for (int i = 1; i < n; i++, l++, r++) {
        if (s[i] == 'l' || s[i] == 'q' || s[i] == 'b') {
            if ((s[l] == 'l' || s[l] == 'q' || s[l] == 'b') && s[i] != s[l]) {
                if ((s[r] == 'l' || s[r] == 'q' || s[r] == 'b') && s[i] != s[r] && s[l] != s[r]) {
                    ans++;
                    i += 2;
                    l += 2;
                    r += 2;
                }
            }
        }
    } 
    cout << ans << '\n';
    return 0;
}