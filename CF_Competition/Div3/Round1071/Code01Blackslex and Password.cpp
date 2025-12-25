#include <bits/stdc++.h>
using namespace std;

int t, k, x;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> k >> x;
        cout << k * x + 1 << endl;
    }
    return 0;
}