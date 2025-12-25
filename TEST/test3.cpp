#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef long long ll;

// 验证k是否可行
bool is_k_valid(const vector<ll>& a, ll k) {
    vector<ll> small; // 收集所有 <k 的元素
    vector<ll> large; // 收集所有 ≥k 的元素
    for (ll num : a) {
        if (num < k) small.push_back(num);
        else large.push_back(num);
    }

    // 步骤1：检查small是否有多个不同值 → 不可行
    unordered_set<ll> small_set(small.begin(), small.end());
    if (small_set.size() > 1) return false;

    // 步骤2：确定候选r
    if (small_set.size() == 1) {
        ll r = small[0];
        // 检查所有large元素是否能通过x≥k得到r
        for (ll num : large) {
            // 条件：(num - r) ≥k （x=num-r ≥k） 或 (num %k == r)（x=k ≥k）
            bool ok = ((num - r) >= k) || (num % k == r);
            if (!ok) return false;
        }
        return true;
    } else {
        // small为空，找r∈[0,k-1]，让所有large元素满足条件
        for (ll r = 0; r < k; ++r) {
            bool all_ok = true;
            for (ll num : large) {
                bool ok = ((num - r) >= k) || (num % k == r);
                if (!ok) {
                    all_ok = false;
                    break;
                }
            }
            if (all_ok) return true;
        }
        return false;
    }
}

ll solve(vector<ll>& a) {
    ll max_a = *max_element(a.begin(), a.end());
    // 从大到小枚举k，找到第一个可行的
    for (ll k = max_a; k >= 1; --k) {
        if (is_k_valid(a, k)) {
            return k;
        }
    }
    return 1; // 兜底：k=1永远可行
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(a) << '\n';
    }
    return 0;
}