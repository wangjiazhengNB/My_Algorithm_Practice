#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int arr[N];
int n, k;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    memset(arr, -1, sizeof arr);
    arr[0] = 0;
    int ans = 0;
    while (k--) {
        int x, y;
        cin >> x >> y;
        if (arr[y] == -1) {
            ans++;
            arr[x] = 0;
            continue;
        }
        else {
            arr[x] = arr[y];
            continue;
        }
    }
    cout << ans << '\n';
    return 0;
}