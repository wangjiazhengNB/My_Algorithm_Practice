#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> t;
    string s;
    while (t--) {
        cin >> n;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '5') {
                cnt = 1;
                break;
            }
        }
        if (cnt == 0) {
            cout << 0 << endl;
            continue;
        }
        int a = -1, b = -1, c = -1, d = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '2') {
                a = i;
                break;
            }
        }
        if (2)
    }
}