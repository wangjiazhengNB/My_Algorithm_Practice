#include <bits/stdc++.h>
using namespace std;

// 暴力方法，对应Java的len1方法
int len1(vector<int>& arr) {
    // Java HashMap<Integer, HashMap<Integer, Integer>> 对应 C++ unordered_map嵌套
    unordered_map<int, unordered_map<int, int>> map;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int zero = 0;
        int one = 0;
        for (int j = i; j < n; j++) {
            zero += (arr[j] == 0) ? 1 : 0;
            one += (arr[j] == 1) ? 1 : 0;
            // 对应Java的map.putIfAbsent(zero, new HashMap<>())
            if (map.find(zero) == map.end()) {
                map[zero] = unordered_map<int, int>();
            }
            // 对应Java的map.get(zero).put(one, map.get(zero).getOrDefault(one, 0) + 1)
            unordered_map<int, int>& innerMap = map[zero];
            innerMap[one] = innerMap.count(one) ? (innerMap[one] + 1) : 1;
        }
    }
    int ans = 0;
    // 遍历外层unordered_map，对应Java的for (int zeros : map.keySet())
    for (auto& outerEntry : map) {
        int zeros = outerEntry.first;
        unordered_map<int, int>& innerMap = outerEntry.second;
        // 遍历内层unordered_map，对应Java的for (int ones : map.get(zeros).keySet())
        for (auto& innerEntry : innerMap) {
            int ones = innerEntry.first;
            int num = innerEntry.second;
            if (num > 1) {
                ans = max(ans, zeros + ones);
            }
        }
    }
    return ans;
}

// 正式方法，对应Java的len2方法
int len2(vector<int>& arr) {
    int leftZero = -1;
    int rightZero = -1;
    int leftOne = -1;
    int rightOne = -1;
    int n = arr.size();
    // 找第一个0的位置
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            leftZero = i;
            break;
        }
    }
    // 找第一个1的位置
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            leftOne = i;
            break;
        }
    }
    // 找最后一个0的位置
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            rightZero = i;
            break;
        }
    }
    // 找最后一个1的位置
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 1) {
            rightOne = i;
            break;
        }
    }
    int p1 = rightZero - leftZero;
    int p2 = rightOne - leftOne;
    return max(p1, p2);
}

// 生成随机数组，对应Java的randomArray方法
vector<int> randomArray(int len) {
    vector<int> ans(len);
    for (int i = 0; i < len; i++) {
        ans[i] = rand() % 2; // 对应Java的Math.random() * 2
    }
    return ans;
}

// 主函数，对应Java的main方法，测试逻辑完全一致
int main() {
    srand((unsigned int)time(nullptr)); // 初始化随机数种子，C++必需
    int N = 500;
    int testTimes = 2000;
    cout << "测试开始" << endl;
    for (int i = 1; i <= testTimes; i++) {
        int n = rand() % N + 2; // 生成2~N+1的随机数，对应Java的(Math.random()*N)+2
        vector<int> arr = randomArray(n);
        // 传递副本，避免方法内部修改原数组（与Java逻辑一致）
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;
        int ans1 = len1(arr1);
        int ans2 = len2(arr2);
        if (ans1 != ans2) {
            cout << "出错了!" << endl;
        }
        if (i % 100 == 0) {
            cout << "测试到第" << i << "组" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}