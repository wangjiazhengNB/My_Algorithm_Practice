#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

long long arr[N][N];
int n, m;

void add(int a, int b, int c, int d, int v) {
    arr[a][b] += v;
    arr[c + 1][b] -= v;
    arr[a][d + 1] -= v;
    arr[c + 1][d + 1] += v;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0, a, b, c, d; i < m; i++) {
        cin >> a >> b >> c >> d;
        add(a, b, c, d, 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}