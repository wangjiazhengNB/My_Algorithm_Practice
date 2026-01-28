#include <bits/stdc++.h>
using namespace std;

const int N = 2050;
const int M = 2050;
int info1[N][M], info2[N][M], info3[N][M], info4[N][M];
int n, m;

int lowbit(int i) {
    return i & -i;
}

void add(int x, int y, int v) {
    int v1 = v;
    int v2 = x * v;
    int v3 = y * v;
    int v4 = x * y * v;
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            info1[i][j] += v1;
            info2[i][j] += v2;
            info3[i][j] += v3;
            info4[i][j] += v4;
        }
    }
}

int sum(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ans += (x + 1) * (y + 1) * info1[i][j] - (y + 1) * info2[i][j] - (x + 1) * info3[i][j] + info4[i][j];
        }
    }
    return ans;
}

void add(int a, int b, int c, int d, int v) {
    add(a, b, v);
    add(c + 1, d + 1, v);
    add(a, d + 1, -v);
    add(c + 1, b, -v);
}

int range(int a, int b, int c, int d) {
    return sum(c, d) - sum(c, b - 1) - sum(a - 1, d) + sum(a - 1, b - 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c, d, v;
    char op;
    cin >> op;
    cin >> n >> m;
    while (cin >> op) {
        if (op == 'X') {
            cin >> n >> m;
        }
        else if (op == 'L') {
            cin >> a >> b >> c >> d >> v;
            add(a, b, c, d, v);
        }
        else {
            cin >> a >> b >> c >> d;
            cout << range(a, b, c, d) << endl;
        }
    }
    return 0;
}

