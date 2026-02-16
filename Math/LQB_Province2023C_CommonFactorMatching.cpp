#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, A = 1e6 + 5;
vector<int> primeFactor[N], m[A];
int arr[N], n;

//分解质因数
void f(int u, int x) {
    int tmp = x;
    for (int i = 2; i * i <= x; i++) {
        if (tmp % i == 0) {
            primeFactor[u].push_back(i);
            m[i].push_back(u);
        }
        while (tmp % i == 0) {
            tmp /= i;
        }
    }
    if (tmp > 1) {
        primeFactor[u].push_back(tmp);
        m[tmp].push_back(u);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) f(i, arr[i]);
    for (int i = 1; i <= n; i++) {
        int first = i, second = 0x3f3f3f3f;
        for (int j = 0; j < primeFactor[i].size(); j++) {
            if (m[primeFactor[i][j]].size() > 1) {
                second = min(second, m[primeFactor[i][j]][1]);
            }
        }
        if (second != 0x3f3f3f3f) {
            cout << first << " " << second << '\n';
            return 0;
        }
    }
    return 0;
}