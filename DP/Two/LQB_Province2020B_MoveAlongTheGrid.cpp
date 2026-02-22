#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 31;
int n, m;

int f(int i, int j) {
    if (i % 2 == 0 && j % 2 == 0) return 0;
    if (i <= 1 || j <= 1) {
        if (i == 1 && j == 1) return 1;
        if (i < 1 || j < 1) return 0;
    } 
    int ans = 0;
    if ((i - 1) % 2 != 0 || j % 2 != 0) {
        ans += f(i - 1, j);
    }
    if (i % 2 != 0 || (j - 1) % 2 != 0) {
        ans += f(i, j - 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cout << f(n, m) << '\n';
    return 0;
}