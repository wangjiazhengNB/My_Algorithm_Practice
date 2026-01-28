#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000001;

// 对应Java的全局数组，下标从1开始（适配题目数据范围）
int arr[MAXN];
int tree[MAXN];
int map_[MAXN]; // 改名为map_，避免与C++标准库map冲突
int ans[MAXN];

// 查询结构体：对应Java的query[][]，存储l、r、原始查询下标
struct Query {
    int l;
    int r;
    int idx;
} query[MAXN];

int n, m;

// lowbit函数：与Java逻辑完全一致
int lowbit(int i) {
    return i & -i;
}

// 树状数组单点更新：i位置加v
void add(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += lowbit(i);
    }
}

// 树状数组求和：1~i的累加和
int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

// 区间查询：l~r的累加和（不同颜色数量）
int range(int l, int r) {
    return sum(r) - sum(l - 1);
}

// 自定义比较函数：按查询的r（右边界）升序排序（对应Java的Comparator）
bool cmp(const Query& a, const Query& b) {
    return a.r < b.r;
}

int main() {
    // 高效输入输出（适配1e6数据量，避免超时，scanf/printf最稳妥）
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &query[i].l, &query[i].r);
        query[i].idx = i; // 记录原始查询下标，用于后续填充答案
    }
    
    // 离线查询核心：按右边界r升序排序（对应Java的Arrays.sort）
    sort(query + 1, query + m + 1, cmp);
    
    // 复刻Java的compute逻辑：遍历查询，同步推进右边界，维护树状数组
    int s = 1; // 当前推进到的数组右边界
    for (int q = 1; q <= m; ++q) {
        int r = query[q].r;
        int l = query[q].l;
        int idx = query[q].idx;
        
        // 把s推进到当前查询的r，处理所有未维护的元素
        for (; s <= r; ++s) {
            int color = arr[s];
            // 如果该颜色之前出现过，删除上一次出现的位置的标记
            if (map_[color] != 0) {
                add(map_[color], -1);
            }
            // 标记当前位置的颜色
            add(s, 1);
            // 更新该颜色最后一次出现的位置为当前s
            map_[color] = s;
        }
        
        // 计算当前查询的答案，存入对应原始下标
        ans[idx] = range(l, r);
    }
    
    // 输出所有查询结果（按原始顺序）
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}