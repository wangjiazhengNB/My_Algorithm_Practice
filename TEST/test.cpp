#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int T, n;
int a[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}