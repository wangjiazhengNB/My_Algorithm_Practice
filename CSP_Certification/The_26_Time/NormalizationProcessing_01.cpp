#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
double a[N], a1, sum = 0, da = 0;
double fa[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    a1 = sum / n;
    for (int i = 1; i <= n; i++) {
        da += (a[i] - a1) * (a[i] - a1);
    }
    da /= n;
    for (int i = 1; i <= n; i++) {
        fa[i] = (a[i] - a1) / sqrt(da);
    }
    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(15) << fa[i] << '\n';
    }
    return 0;
}