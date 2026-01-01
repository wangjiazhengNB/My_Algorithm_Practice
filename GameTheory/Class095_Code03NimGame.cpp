#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans;
        cin >> ans;
        for (int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            ans ^= x;
        }
        if (ans != 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}