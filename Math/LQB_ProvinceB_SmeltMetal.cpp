#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n;
int arr[N][2];

bool check1(int m) {
    for (int i = 1; i <= n; i++) {
        if (arr[i][0] / m < arr[i][1]) return false;
    }
    return true;
}

bool check2(int m) {
    for (int i = 1; i <= n; i++) {
        if (arr[i][0] / m > arr[i][1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int ma, mi;
    int l = 1, r = 1e9, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (check1(m)) {
            ma = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    l = 1, r = 1e9;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (check2(m)) {
            mi = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << mi << " " << ma << '\n';
    return 0;
}