#include <iostream>
#include <vector>
using namespace std;

int n, m, t;
vector<int> as;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> t;
    as.resize(n * m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> as[cnt++];
        }
    }

    while (t--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            // 重塑：仅修改行列数，O(1) 时间！
            n = x;
            m = y;
        }
        else if (op == 2) {
            vector<int> tmp(m * n);
            int tmp_cnt = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    tmp[tmp_cnt++] = as[j * m + i];
                }
            }
            as = tmp;
            swap(n, m); // 交换行列数
        }
        else if (op == 3) {
            // 查询：行优先公式计算下标，O(1)
            cout << as[x * m + y] << '\n';
        }
    }
    return 0;
}