#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
ll a[25], c[25], b[25];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] * a[i];
    }
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        b[i + 1] = ((m % c[i + 1]) - tmp) / c[i];
        tmp +=  c[i] * b[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
}