#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

// 保持与Java一致的常量定义
#define MAXN 100001
#define LIMIT 17

// 全局数组定义（索引从1开始使用，与Java逻辑一致）
// 避免与cmath库的log2函数命名冲突，将log2改为log_table
int arr[MAXN];
int log_table[MAXN];
int bucket[MAXN];
int left_[MAXN];  // 避免与C++关键字left冲突，改为left_
int right_[MAXN]; // 避免与C++关键字right冲突，改为right_
int stmax[MAXN][LIMIT];

// 构建预处理数组和ST表，逻辑与Java的build函数完全一致
void build(int n) {
    // 题目给定的数值范围-100000 ~ +100000，设置arr[0]为不会到达的数字
    arr[0] = -23333333;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i - 1] != arr[i]) {
            right_[cnt] = i - 1;
            left_[++cnt] = i;
        }
        bucket[i] = cnt;
    }
    right_[cnt] = n;
    
    // 初始化对数表和ST表第0层
    log_table[0] = -1;
    for (int i = 1; i <= cnt; ++i) {
        log_table[i] = log_table[i >> 1] + 1;
        stmax[i][0] = right_[i] - left_[i] + 1;
    }
    
    // 构建ST表的高层
    for (int p = 1; p <= log_table[cnt]; ++p) {
        for (int i = 1; i + (1 << p) - 1 <= cnt; ++i) {
            stmax[i][p] = max(stmax[i][p - 1], stmax[i + (1 << (p - 1))][p - 1]);
        }
    }
}

// 查询区间[l, r]出现次数最多的数的个数，逻辑与Java的query函数完全一致
int query(int l, int r) {
    // 处理l > r的情况，交换两者
    if (l > r) {
        swap(l, r); // C++的std::swap等价于Java的手动tmp交换
    }
    int lbucket = bucket[l];
    int rbucket = bucket[r];
    
    if (lbucket == rbucket) {
        return r - l + 1;
    }
    
    // 计算最左侧桶、最右侧桶在区间内的元素个数
    int a = right_[lbucket] - l + 1;
    int b = r - left_[rbucket] + 1;
    int c = 0;
    
    // 计算中间完整桶的最大元素个数（若存在中间桶）
    if (lbucket + 1 < rbucket) {
        int from = lbucket + 1;
        int to = rbucket - 1;
        int p = log_table[to - from + 1];
        c = max(stmax[from][p], stmax[to - (1 << p) + 1][p]);
    }
    
    // 返回三者中的最大值
    return max(max(a, b), c);
}

// 生成随机有序数组，逻辑与Java的randomArray完全一致
void randomArray(int n, int v) {
    for (int i = 1; i <= n; ++i) {
        // 对应Java的 (Math.random() * 2 * v) - v，生成[-v, v]范围内的随机数
        arr[i] = (rand() % (2 * v + 1)) - v;
    }
    // 排序数组（索引1到n，与Java的Arrays.sort(arr, 1, n+1)一致）
    sort(arr + 1, arr + n + 1);
}

// 暴力验证函数，直接统计词频，逻辑与Java的checkQuery完全一致
int checkQuery(int l, int r) {
    // 处理l > r的情况，交换两者
    if (l > r) {
        swap(l, r);
    }
    // unordered_map对应Java的HashMap，用于统计词频
    unordered_map<int, int> map;
    for (int i = l; i <= r; ++i) {
        map[arr[i]]++; // 等价于Java的map.put(arr[i], map.getOrDefault(arr[i], 0) + 1)
    }
    
    // 找出最大词频
    int ans = 0;
    for (auto& pair : map) {
        ans = max(ans, pair.second);
    }
    return ans;
}

// 主函数（对数器验证），逻辑与Java的main完全一致
int main() {
    // 设置随机数种子，保证每次运行生成不同的随机数组（Java默认自动随机，C++需要手动设置）
    srand((unsigned int)time(nullptr));
    
    cout << "测试开始" << endl;
    int n = 10000;
    int v = 100;
    int m = 5000;
    
    randomArray(n, v);
    build(n);
    
    for (int i = 1; i <= m; ++i) {
        // 生成[1, n]范围内的随机查询区间l和r
        int l = (rand() % n) + 1;
        int r = (rand() % n) + 1;
        
        if (query(l, r) != checkQuery(l, r)) {
            cout << "出错了!" << endl;
            return 1; // 出错直接退出程序
        }
    }
    cout << "测试结束" << endl;
    return 0;
}