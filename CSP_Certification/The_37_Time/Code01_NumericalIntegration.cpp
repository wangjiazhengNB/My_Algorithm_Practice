#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int b, c, l, r;
    cin >> b >> c >> l >> r;
    long long ans = 0; 
    int start = (l % 2 == 0) ? l : l + 1;
    for (int x = start; x <= r; x += 2) {
        ans += (1LL * x * x + 1LL * b * x + c); 
    }
    ans *= 2;
    cout << ans << endl;
    return 0;
}