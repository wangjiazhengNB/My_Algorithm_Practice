#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 10005;
int arr[N];
int n, m, p, q, cnt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> p >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[cnt++];
        }
    }

    cnt = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            if (j > 0) cout << " ";
            cout << arr[cnt++];
        }
        cout << '\n';
    }

    return 0;
}