#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int cnt[N];
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 != 0) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}