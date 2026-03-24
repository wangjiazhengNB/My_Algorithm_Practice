#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vector<set<int>> article(m + 1);
    vector<int> cnt(m + 1);

    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        for (int j = 1, c; j <= len; j++) {
            cin >> c;
            article[c].emplace(i);
            cnt[c]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << article[i].size() << " " << cnt[i] << '\n';
    }
    return 0;
}