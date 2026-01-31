#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        int a2, a3, a4, b4, b6;
        int cnt = 0;
        cin >> a2 >> a3 >> a4 >> b4 >> b6;
        while (b6 > 0 && a3 - 1 > 0) {
            cnt += 6;
            b6--, a3 -= 2;
        }
        while (b6 > 0 && a2 > 0 && a4 > 0) {
            cnt += 6;
            b6--, a2--, a4--;
        }
        while (b6 > 0 && a2 - 2 > 0) {
            cnt += 6;
            b6--, a2 -= 3;
        }
        while (b4 > 0 && a4 > 0) {
            cnt += 4;
            b4--, a4--;
        }
        while (b4 > 0 && a2 - 1 > 0) {
            cnt += 4;
            b4--, a2 -= 2;
        }
        while (b6 > 0 && a3 > 0 && a2 > 0) {
            cnt += 5;
            b6--, a3--, a2--;
        }
        while (b4 > 0 && a3 > 0) {
            cnt += 3;
            b4--, a3--;
        }


        while (b6 > 0 && a2 - 1 > 0) {
            cnt += 4;
            b6--, a2 -= 2;
        }
        while (b6 > 0 && a4 > 0) {
            cnt += 4;
            b6--, a4--;
        }
        while (b4 > 0 && a2 > 0) {
            cnt += 2;
            b4--, a2--;
        }
        while (b6 > 0 && a3 > 0) {
            cnt += 3;
            b6--, a3--;
        }
        while (b6 > 0 && a2 > 0) {
            cnt += 2; 
            b6--, a2--;
        }
        cout << cnt << '\n';
    }
}