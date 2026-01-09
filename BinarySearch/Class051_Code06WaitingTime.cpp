#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int waitingTime1(vector<int>& arr, int m) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        heap.push({0, arr[i]});
    }
    for (int i = 0; i < m; i++) {
        auto cur = heap.top();
        heap.pop();
        cur.first += cur.second;
        heap.push(cur);
    }
    return heap.top().first;
}

int f(vector<int>& arr, int time) {
    int ans = 0;
    for (int num : arr) {
        ans += (time / num) + 1;
    }
    return ans;
}

int waitingTime2(vector<int>& arr, int w) {
    int min_val = INT_MAX;
    for (int x : arr) {
        min_val = min(min_val, x);
    }
    int ans = 0;
    int l = 0, r = min_val * w;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (f(arr, mid) >= w + 1) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

vector<int> randomArray(int n, int v) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % v + 1;
    }
    return arr;
}

int main() {
    srand(time(0));
    cout << "测试开始" << endl;
    int N = 50;
    int V = 30;
    int M = 3000;
    int testTime = 20000;
    for (int i = 0; i < testTime; i++) {
        int n = rand() % N + 1;
        vector<int> arr = randomArray(n, V);
        int m = rand() % M;
        int ans1 = waitingTime1(arr, m);
        int ans2 = waitingTime2(arr, m);
        if (ans1 != ans2) {
            cout << "出错了" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}