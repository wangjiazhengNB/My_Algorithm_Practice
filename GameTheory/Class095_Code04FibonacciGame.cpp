#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        int eor = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            sum += (x == 1 ? 1 : 0);
            eor ^= x;
        }
        if (sum == n) {
            if ((n & 1) == 0) cout << "John" << endl;
            else cout << "Brother" << endl;
            continue;
        }
        if (eor != 0) {
            cout << "John" << endl;
        }
        else {
            cout << "Brother" << endl;
        }
    }
    return 0;
}