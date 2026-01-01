#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cstdlib>

using namespace std;

// 1. 先定义 finish 函数（在 len1 调用前）
bool finish(vector<int>& list, unordered_set<int>& set) {
    int len = list.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int abs_val = abs(list[i] - list[j]);
            if (set.count(abs_val) == 0) {
                list.push_back(abs_val);
                set.insert(abs_val);
            }
        }
    }
    return len == list.size();
}

// 2. 先定义 gcd 函数（在 len2 调用前）
int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}

// 再定义 len1 函数（可正常调用 finish）
int len1(const vector<int>& arr) {
    vector<int> list;
    unordered_set<int> set;
    for (int num : arr) {
        list.push_back(num);
        set.insert(num);
    }
    while (!finish(list, set))
        ;
    return list.size();
}

// 再定义 len2 函数（可正常调用 gcd）
int len2(const vector<int>& arr) {
    int max_val = 0;
    int gcd_val = 0;
    for (int num : arr) {
        max_val = max(max_val, num);
        if (num != 0) {
            gcd_val = num;
        }
    }
    if (gcd_val == 0) {
        return arr.size();
    }
    unordered_map<int, int> cnts;
    for (int num : arr) {
        if (num != 0) {
            gcd_val = gcd(gcd_val, num);
        }
        cnts[num]++;
    }
    int ans = max_val / gcd_val;
    int max_cnt = 0;
    for (auto& entry : cnts) {
        int key = entry.first;
        int count = entry.second;
        if (key != 0) {
            ans += count - 1;
        }
        max_cnt = max(max_cnt, count);
    }
    int zero_cnt = cnts.count(0) ? cnts[0] : (max_cnt > 1 ? 1 : 0);
    ans += zero_cnt;
    return ans;
}

// 生成随机数组（逻辑不变）
vector<int> randomArray(int n, int v) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = rand() % v;
    }
    return ans;
}

// 主函数（逻辑不变）
int main() {
    int N = 50;
    int V = 100;
    int testTimes = 2000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        int n = rand() % N + 1;
        vector<int> nums = randomArray(n, V);
        int ans1 = len1(nums);
        int ans2 = len2(nums);
        if (ans1 != ans2) {
            cout << "出错了！" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}