#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s1, s2;
    int ans = 0;
    cin >> s1 >> s2;
    int l = s1.size() - 1;
    int r = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '#' || s2[i] == '#') {
            l = min(l, i);
            r = max(r, i);
        }
    }
    for (int i = l; i < r; i++) {
        if (s1[i] == '#' && s2[i] == '.' && s1[i + 1] == '.') {
            ans++;
            s1[i + 1] = '#';
        }
        if (s1[i] == '.' && s2[i] == '#' && s2[i + 1] == '.') {
            ans++;
            s2[i + 1] = '#';
        }
        if (s1[i] == '#' && s2[i] == '#' && s1[i + 1] == '.' && s2[i + 1] == '.') {
            int p = i, q = i;
            for (int j = i + 1; j <= r; j++) {
                if (s1[j] == '#') {
                    p = j;
                    break;
                }
                if (s2[j] == '#') {
                    q = j;
                    break;
                }
            }
            if (p >= q) {
                s1[i + 1] = '#';
                ans++;
            }
            else {
                s2[i + 1] = '#';
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}