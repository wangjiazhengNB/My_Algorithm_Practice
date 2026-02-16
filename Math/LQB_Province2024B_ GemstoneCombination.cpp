#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
int arr[N];
vector<int> v[N];
int maxn = -1e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                v[j].push_back(arr[i]);
                if (arr[i] / j != j) {
                    v[arr[i] / j].push_back(arr[i]);
                }
            }
        }
    }
    for (int i = maxn; i >= 1; i--) {
        if (v[i].size() >= 3) {
            cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << '\n';
            break;
        }
    }
    return 0;
}