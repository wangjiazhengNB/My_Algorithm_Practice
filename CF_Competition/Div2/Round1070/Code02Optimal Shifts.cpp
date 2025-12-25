#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N];

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s; 
        s += s;
        n *= 2;
        int cur = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cur = 0;
            else cur++;
            res = max(res, cur);
        }
        cout << res << '\n';
    }
    return 0;
}