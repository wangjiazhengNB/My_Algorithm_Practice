#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
pair<int, int> a[N];
pair<int, int> b[N];
int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
        for (int j = 0; j < n; j++) {
            b[i].first += a[j].first;
            b[i].second += a[j].second;
        }
        cout << b[i].first << " " << b[i].second << '\n';
    }
    return 0;
}