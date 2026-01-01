#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int i, vector<int>& sum, vector<int>& cnt) {
    if (i == arr.size()) {
        int ans = 0;
        for (int j = 0; j < sum.size(); j++) {
            if (cnt[j] == 0) {
                return INT_MAX;
            }
            ans += sum[j] / cnt[j];
        }
        return ans;
    }
    else {
        int ans = INT_MAX;
        for (int j = 0; j < sum.size(); j++) {
            sum[j] += arr[i];
            cnt[j]++;
            ans = min(ans, f(arr, i + 1, sum, cnt));
            sum[j] -= arr[i];
            cnt[j]--;
        }
        return ans;
    }
}

int minAverageSum1(vector<int>& arr, int k) {
    vector<int> sum(k, 0);
    vector<int> cnt(k, 0);
    return f(arr, 0, sum, cnt);
}

int minAverageSum2(vector<int>& arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < k - 1; i++) {
        sum += arr[i];
    }
    int sum1 = 0;
    for (int i = k - 1; i < n; i++) {
        sum1 += arr[i];
    }
    sum1 /= (n - k + 1);
    sum += sum1;
    return sum;
}

vector<int> randomArray(int n, int v) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = rand() % v + 1; // 可选：删除+1，复刻Java逻辑
    }
    return ans;
}

int main() {
    srand((unsigned int)time(nullptr)); // 修正1：初始化随机数种子
    int N = 8;
    int V = 100;
    int testTimes = 10;
    cout << "测试开始" << endl;
    for (int i = 1; i <= testTimes; i++) {
        int n = rand() % N + 1;
        // 修正2：k的范围[1, n]，符合题目要求，删除无用的K变量
        int k = rand() % n + 1;
        vector<int> arr = randomArray(n, V);
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;
        int ans1 = minAverageSum1(arr1, k);
        int ans2 = minAverageSum2(arr2, k);
        if (ans1 != ans2) {
            cout << "出错了" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
}