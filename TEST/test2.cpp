#include <bits/stdc++.h>
using namespace std;

int t, a, b;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int a1 = a, b1 = b;
        int n1 = 0, n2 = 0;
        for (int i = 1; i <= a1; i *= 4) {
            n1++;
            a1 -= i;
        }
        for (int i = 2; i <= b1; i *= 4) {
            n2++;
            b1 -= i;
        }
        int cnt1 = n1 * 2 - 1;
        int cnt2 = n2 * 2;
        int max1 = abs(cnt1 - cnt2) == 1 ? max(cnt1, cnt2) : min(cnt1, cnt2) + 1;
        n1 = 0, n2 = 0;
        a1 = a, b1 = b;
        for (int i = 1; i <= b1; i *= 4) {
            n1++;
            b1 -= i;
        }
        for (int i = 2; i <= a1; i *= 4) {
            n2++;
            a1 -= i;
        }
        cnt1 = n1 * 2 - 1;
        cnt2 = n2 * 2;
        int max2 = abs(cnt1 - cnt2) == 1 ? max(cnt1, cnt2) : min(cnt1, cnt2) + 1;
        int ans = max(max1, max2);
        cout << ans << endl;
    }
    return 0;
}