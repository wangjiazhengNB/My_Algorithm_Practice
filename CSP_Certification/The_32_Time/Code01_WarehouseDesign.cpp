#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 1005, M = 11;
int arr[N][M];
int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        for (int j = 1; j <= n; j++, cnt++) {
            bool flag = true;
            if (i == j) continue;
            for (int k = 1; k <= m; k++) {
                if (arr[i][k] >= arr[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << j << '\n';
                break;
            }
            if (!flag && cnt == n) {
                cout << 0 << '\n';
                break;
            }
        }
    }
    return 0;
}