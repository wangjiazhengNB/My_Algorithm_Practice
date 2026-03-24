#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 全部换成 unordered_set，提速拉满
// 因为这里我不需要排序，所以我无脑用unordered_set
unordered_set<string> s1, s2;
unordered_set<string> check;
int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string c;
        cin >> c;
        for (int j = 0; j < c.size(); j++) {
            if (c[j] >= 'A' && c[j] <= 'Z') {
                c[j] += 32;
            }
        }
        s1.emplace(c);
        check.emplace(c);
    }

    for (int i = 1; i <= m; i++) {
        string c;
        cin >> c;
        for (int j = 0; j < c.size(); j++) {
            if (c[j] >= 'A' && c[j] <= 'Z') {
                c[j] += 32;
            }
        }
        s2.emplace(c);
        check.emplace(c);
    }

    int ans1 = 0, ans2 = check.size();
    for (auto& c : s1) {
        if (s2.count(c)) ans1++;
    }

    cout << ans1 << '\n' << ans2;
    return 0;
}