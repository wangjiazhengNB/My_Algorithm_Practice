#include <bits/stdc++.h>
using namespace std;


const int OFFSET = 300000;
const int MAXN = 600010;

int diff[MAXN]; // 差分数组

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    // 1. 处理所有出行计划，更新差分数组
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        int L = t - k - c + 1;
        int R = t - k;
        diff[L + OFFSET]++;
        diff[R + OFFSET + 1]--;
    }

    for (int i = 1; i < MAXN; i++) {
        diff[i] += diff[i-1];
    }

    while (m--) {
        int q;
        cin >> q;
        cout << diff[q + OFFSET] << '\n';
    }

    return 0;
}