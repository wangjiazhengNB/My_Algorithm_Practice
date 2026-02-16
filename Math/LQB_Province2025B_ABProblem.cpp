#include <bits/stdc++.h>
using namespace std;

const int N = 2e6; 
int f[N], s[N];
int n;

void pre(int x) {
    bool flag = 0;
    for (int i = 1; i * i <= x; i++) {
        f[x] += !(x % i);
        if (i * i == x) flag = 1;
    }
    f[x] *= 2;
    f[x] -= flag;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) pre(i);

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + f[i];
    for (int i = 1; i < n; i++) {
            ans += f[i] * s[n - i];
    }
    cout << ans << '\n';
    return 0;
}