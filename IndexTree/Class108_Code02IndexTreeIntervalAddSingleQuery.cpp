#include <iostream>
using namespace std;

const int MAXN = 500002;

// 树状数组维护差分信息
int tree[MAXN];

// 对应Java的static int n, m
int n, m;

// lowbit函数：
int lowbit(int i) {
    return i & -i;
}

// 单点增加（树状数组核心操作）
void add(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += lowbit(i);
    }
}

// 求1~i的累加和，逻辑与Java一致（单点查询的核心）
int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    // 初始化：将原始数组转为差分形式存入树状数组
    for (int i = 1, v; i <= n; ++i) {
        cin >> v;
        add(i, v);
        add(i + 1, -v);
    }
    // 处理m次操作
    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            // 范围增加操作：[l, r]加v
            int l, r, v;
            cin >> l >> r >> v;
            add(l, v);
            add(r + 1, -v);
        } else {
            // 单点查询操作：查询index位置的值
            int index;
            cin >> index;
            cout << sum(index) << endl;
        }
    }
    return 0;
}