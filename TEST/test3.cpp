#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];
        
        // 统计a→b的合法偏移量d
        int cntD = 0;
        for (int d = 0; d < n; ++d) {
            bool valid = true;
            for (int u = 0; u < n; ++u) {
                if (a[u] >= b[(u + d) % n]) {
                    valid = false;
                    break;
                }
            }
            if (valid) cntD++;
        }
        
        // 统计b→c的合法偏移量e
        int cntE = 0;
        for (int e = 0; e < n; ++e) {
            bool valid = true;
            for (int v = 0; v < n; ++v) {
                if (b[v] >= c[(v + e) % n]) {
                    valid = false;
                    break;
                }
            }
            if (valid) cntE++;
        }
        
        // 计算合法组合数
        long long ans = 1LL * cntD * cntE * n;
        cout << ans << '\n';
    }
    return 0;
}