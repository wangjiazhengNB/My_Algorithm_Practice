#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> tree;  // 二维树状数组，下标从1开始
    vector<vector<int>> nums;  // 原始数值备份，下标从1开始
    int n;                     // 矩阵行数（原始矩阵下标0开始）
    int m;                     // 矩阵列数（原始矩阵下标0开始）

    // 等价于Java的lowbit方法，获取i最右侧的1
    int lowbit(int i) {
        return i & -i;
    }

    // 二维树状数组单点增加：在(x,y)位置加v（x,y是树状数组下标，从1开始）
    void add(int x, int y, int v) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                tree[i][j] += v;
            }
        }
    }

    // 二维树状数组求和：求(1,1)到(x,y)的累加和（x,y是树状数组下标）
    int sum(int x, int y) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                ans += tree[i][j];
            }
        }
        return ans;
    }

public:
    // 构造函数：入参是原始二维矩阵（下标0开始），初始化树状数组
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        // 初始化树状数组和数值备份数组，大小为(n+1)x(m+1)（下标从1开始）
        tree = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        nums = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        // 遍历原始矩阵，调用update初始化（逻辑与Java完全一致）
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    // 单点更新：原始矩阵(x,y)位置更新为v（x,y是0开始的下标）
    void update(int x, int y, int v) {
        // 计算差值：新值 - 旧值，转化为树状数组的单点增加
        add(x + 1, y + 1, v - nums[x + 1][y + 1]);
        // 更新备份数组的数值
        nums[x + 1][y + 1] = v;
    }

    // 范围查询：原始矩阵(a,b)到(c,d)的累加和（所有下标0开始）
    int sumRegion(int a, int b, int c, int d) {
        // 下标转换+二维前缀和计算，逻辑与Java完全一致
        return sum(c + 1, d + 1) - sum(a, d + 1) - sum(c + 1, b) + sum(a, b);
    }
};

int main() {
    return 0;
}