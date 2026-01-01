#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100001;
const int MAXN = 20001;

int factors[MAXV];
int father[MAXN];
int size_[MAXN]; // 用size_
int n; // 

// 质因子分解函数
void f(int n) {
    for (int i = 2; (long long)i * i <= n; i++) { // 强转long long避免i*i溢出
        if (n % i == 0) {
            cout << i << endl;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        cout << n << endl;
    }
}

// 并查集初始化
void build() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
        size_[i] = 1;
    }
    memset(factors, -1, sizeof(factors));
}

// 并查集查找（路径压缩）
int find(int i) {
    if (i != father[i]) {
        father[i] = find(father[i]);
    }
    return father[i];
}

// 并查集合并
void union_(int x, int y) { // 用union_避免和std::union重名
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        father[fx] = fy;
        size_[fy] += size_[fx];
    }
}

// 找最大组件大小，对应Java的maxSize()
int maxSize() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, size_[i]); // 对应Java的Math.max
    }
    return ans;
}

// 正式方法，对应Java的largestComponentSize(int[] arr)
int largestComponentSize(vector<int>& arr) {
    n = arr.size(); // 对应Java的arr.length
    build();
    for (int i = 0, x; i < n; i++) {
        x = arr[i];
        for (int j = 2; (long long)j * j <= x; j++) { // 强转long long避免溢出
            if (x % j == 0) {
                if (factors[j] == -1) {
                    factors[j] = i;
                } else {
                    union_(factors[j], i);
                }
                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x > 1) {
            if (factors[x] == -1) {
                factors[x] = i;
            } else {
                union_(factors[x], i);
            }
        }
    }
    return maxSize();
}

// 测试主函数，对应Java的main(String[] args)
int main() {
    // 测试质因子分解函数
    int test_n = 4012100;
    f(test_n);

    // 可选：测试largestComponentSize（示例）
    // vector<int> arr = {4,6,15,35};
    // cout << "最大组件大小：" << largestComponentSize(arr) << endl;

    return 0;
}