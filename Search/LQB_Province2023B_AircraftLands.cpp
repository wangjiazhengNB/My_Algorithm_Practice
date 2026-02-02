#include <bits/stdc++.h>
using namespace std;

const int N = 11;
struct Plane {
    int t;
    int d;
    int l;
} plane[N];

int T, n;
bool flag = false;

void swap(int i, int j) {
    Plane temp;
    temp = plane[i];
    plane[i] = plane[j];
    plane[j] = temp;
}

void dfs(int i, int time) {
    if (flag) return;
    if (i == n + 1) {
        flag = true;
        return;
    }
    for (int j = i; j <= n; j++) {
        int start = max(time, plane[j].t);
        if (start <= plane[j].t + plane[j].d) {
            swap(i, j);
            dfs(i + 1, start + plane[i].l);
            swap(i, j);
        }
    }
} 

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        flag = false;
        for (int i = 1, t, d, l; i <= n; i++) {
            cin >> t >> d >> l;
            plane[i] = {t, d, l};
        }
        dfs(1, 0);
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

