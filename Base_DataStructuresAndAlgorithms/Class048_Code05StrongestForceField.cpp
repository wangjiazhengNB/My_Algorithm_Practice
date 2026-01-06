#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 210;
ll xs[N], ys[N], diff[N][N];


class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        int n = forceField.size();
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            ll x = forceField[i][0];
            ll y = forceField[i][1];
            ll r = forceField[i][2];
            xs[cnt1++] = x * 2 - r;
            xs[cnt1++] = x * 2 + r;
            ys[cnt2++] = y * 2 - r;
            ys[cnt2++] = y * 2 + r;
        }
        int size1 = sorted1(cnt1);
        int size2 = sorted2(cnt2);
        memset(diff, 0, sizeof diff);
        for (int i = 0; i < n; i++) {
            ll x = forceField[i][0];
            ll y = forceField[i][1];
            ll r = forceField[i][2];
            int a = rank(1, x * 2 - r, size1);
            int b = rank(2, y * 2 - r, size2);
            int c = rank(1, x * 2 + r, size1);
            int d = rank(2, y * 2 + r, size2);
            getdiff(a, b, c, d, 1);
        }
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            }
        }
        ll maxs = INT_MIN;
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                maxs = max(maxs, diff[i][j]);
            }
        }
        return maxs;
    }
    void getdiff(int a, int b, int c, int d, int v) {
        diff[a][b] += v;
        diff[c + 1][b] -= v;
        diff[a][d + 1] -= v;
        diff[c + 1][d + 1] += v;
    }
    int rank(int flag, ll x, int size) {
        int l = 0, r = size - 1, m, ans = size;
        if (flag == 1) {
            while (l <= r) {
                m = l + r >> 1;
                if (xs[m] >= x) {
                    ans = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
        else {
             while (l <= r) {
                m = l + r >> 1;
                if (ys[m] >= x) {
                    ans = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
        return ans + 1;
    }
    int sorted1(int t) {
        int size1 = 1;
        sort(xs, xs + t);
        for (int i = 1; i < t; i++) {
            if (xs[i] != xs[i - 1]) {
                xs[size1++] = xs[i];
            }
        }
        return size1;
    }
    int sorted2(int t) {
        int size2 = 1;
        sort(ys, ys + t);
        for (int i = 1; i < t; i++) {
            if (ys[i] != ys[i - 1]) {
                ys[size2++] = ys[i];
            }
        }
        return size2;
    }
};

int main() {
    return 0;
}

// 第二份代码，合理版（Ai 生成）
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const int N = 210;

// class Solution {
// private:
//     // 通用离散化函数：排序+去重，返回去重后的长度
//     int discretize(ll arr[], int len) {
//         if (len == 0) return 0;
//         sort(arr, arr + len);
//         int unique_len = 1;
//         for (int i = 1; i < len; ++i) {
//             if (arr[i] != arr[unique_len - 1]) {
//                 arr[unique_len++] = arr[i];
//             }
//         }
//         return unique_len;
//     }

//     // 通用二分查找：找arr中第一个≥x的下标，返回1-based索引
//     int find_rank(ll arr[], int unique_len, ll x) {
//         int l = 0, r = unique_len - 1;
//         int ans = unique_len; // 所有元素<x时，返回unique_len（边界）
//         while (l <= r) {
//             int mid = (l + r) >> 1;
//             if (arr[mid] >= x) {
//                 ans = mid;
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return ans + 1; // 转1-based，适配差分矩阵
//     }

//     // 二维差分更新函数
//     void update_diff(ll diff[][N], int a, int b, int c, int d, int val) {
//         diff[a][b] += val;
//         diff[c + 1][b] -= val;
//         diff[a][d + 1] -= val;
//         diff[c + 1][d + 1] += val;
//     }

// public:
//     int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
//         int n = forceField.size();
//         ll xs[N] = {0}, ys[N] = {0}; // 局部数组替代全局，降低耦合
//         ll diff[N][N] = {0};         // 局部差分矩阵，无需memset初始化
//         int cnt_x = 0, cnt_y = 0;

//         // 步骤1：收集所有力场的边界坐标（2倍化避免小数）
//         for (auto& ff : forceField) {
//             ll x = ff[0], y = ff[1], r = ff[2];
//             xs[cnt_x++] = x * 2 - r;
//             xs[cnt_x++] = x * 2 + r;
//             ys[cnt_y++] = y * 2 - r;
//             ys[cnt_y++] = y * 2 + r;
//         }

//         // 步骤2：离散化x/y坐标
//         int len_x = discretize(xs, cnt_x);
//         int len_y = discretize(ys, cnt_y);

//         // 步骤3：遍历力场，标记差分矩阵
//         for (auto& ff : forceField) {
//             ll x = ff[0], y = ff[1], r = ff[2];
//             // 映射到离散化后的1-based下标
//             int a = find_rank(xs, len_x, x * 2 - r);
//             int b = find_rank(ys, len_y, y * 2 - r);
//             int c = find_rank(xs, len_x, x * 2 + r);
//             int d = find_rank(ys, len_y, y * 2 + r);
//             update_diff(diff, a, b, c, d, 1);
//         }

//         // 步骤4：计算差分矩阵的前缀和（得到覆盖次数）
//         for (int i = 1; i <= len_x; ++i) {
//             for (int j = 1; j <= len_y; ++j) {
//                 diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
//             }
//         }

//         // 步骤5：找最大覆盖次数
//         ll max_cnt = 0;
//         for (int i = 1; i <= len_x; ++i) {
//             for (int j = 1; j <= len_y; ++j) {
//                 max_cnt = max(max_cnt, diff[i][j]);
//             }
//         }

//         return max_cnt;
//     }
// };