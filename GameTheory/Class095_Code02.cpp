#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 6 != 0) {
            cout << "October wins!" << endl;
        }
        else {
            cout << "Roy wins!" << endl;
        }
    }
    return 0;
}