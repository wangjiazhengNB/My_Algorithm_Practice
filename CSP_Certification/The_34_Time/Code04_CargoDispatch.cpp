//暴力写法骗分用的

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct WareHouse {
    int b;
    int c;
    vector<int> cargo;
};
int n, m, v;

int f(int i, int money, int cost, vector<WareHouse>& whinfo) {
    if (money >= v) {
        return cost;
    }
    if (i == n) {
        return 0x3f3f3f3f;
    }

    int ans = 0x3f3f3f3f;

    ans = f(i + 1, money, cost, whinfo);

    int new_money = money - whinfo[i].b;
    int new_cost = cost + whinfo[i].b;

    sort(whinfo[i].cargo.begin(), whinfo[i].cargo.end());
    int sum_a = 0;
    for (int j = 0; j < whinfo[i].cargo.size(); j++) {
        sum_a += whinfo[i].cargo[j];
        int tmp_money = new_money + sum_a - (j + 1) * whinfo[i].c;
        int tmp_cost = new_cost + (j + 1) * whinfo[i].c;
        ans = min(ans, f(i, tmp_money, tmp_cost, whinfo));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> v;
    vector<WareHouse> whinfo(n);
    for (int i = 0; i < n; i++) {
        cin >> whinfo[i].b>> whinfo[i].c;
    }
    for (int i = 0; i < m; i++) {
        int a, t;
        cin >> a >> t;
        whinfo[t].cargo.push_back(a);
    }
    cout << f(0, 0, 0, whinfo) << '\n';
    return 0;
}

*/

//正确解法，分组背包
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = 0x3f3f3f3f;

struct WareHouse {
    int b;          // 基本费
    int c;          // 计件费
    vector<int> cargo; // 货物价值
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;

    vector<WareHouse> wh(n);
    int max_cost = 0; // 总费用上限

    // 读取仓库信息
    for (int i = 0; i < n; ++i) {
        cin >> wh[i].b >> wh[i].c;
        max_cost += wh[i].b; // 先加基本费上限
    }
    max_cost += m * 20; // 再加计件费上限（c_j≤20）

    // 读取货物信息
    for (int i = 0; i < m; ++i) {
        int a, t;
        cin >> a >> t;
        wh[t].cargo.push_back(a);
    }

    // 预处理：每个仓库货物按价值降序排序
    for (auto& w : wh) {
        sort(w.cargo.rbegin(), w.cargo.rend());
    }

    // 初始化DP：dp[c] = 花c元能获得的最大价值
    vector<int> dp(max_cost + 1, -INF);
    dp[0] = 0; // 0元，0价值

    // 分组背包处理每个仓库
    for (auto& w : wh) {
        // 计算选k件的前缀和（总价值）
        vector<int> sum_a(w.cargo.size() + 1, 0);
        for (int k = 1; k <= w.cargo.size(); ++k) {
            sum_a[k] = sum_a[k-1] + w.cargo[k-1];
        }

        // 生成本仓库选项：(delta_cost, delta_value)
        vector<pair<int, int>> opts;
        opts.emplace_back(0, 0); // 不卖
        for (int k = 1; k <= w.cargo.size(); ++k) {
            int dc = w.b + k * w.c;
            int da = sum_a[k];
            opts.emplace_back(dc, da);
        }

        // 逆序遍历（分组背包）
        for (int c = max_cost; c >= 0; --c) {
            if (dp[c] == -INF) continue;
            for (auto& [dc, da] : opts) {
                int nc = c + dc;
                if (nc > max_cost) continue;
                if (dp[nc] < dp[c] + da) {
                    dp[nc] = dp[c] + da;
                }
            }
        }
    }

    // 找最小费用c，满足：dp[c] - c >= v
    int ans = INF;
    for (int c = 0; c <= max_cost; ++c) {
        if (dp[c] != -INF && dp[c] - c >= v) {
            ans = c;
            break; // 因为c从小到大遍历，第一个满足的就是最小费用
        }
    }

    cout << ans << endl;
    return 0;
}