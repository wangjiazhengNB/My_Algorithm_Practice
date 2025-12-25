#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int T, n;
int a[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mx = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
            if (mx == a[i]) res++;
        }
        cout << n - res << endl;
    }
    return 0;
}