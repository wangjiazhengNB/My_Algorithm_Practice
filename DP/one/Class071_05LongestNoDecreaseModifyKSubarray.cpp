#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int arr[N], rights[N], endss[N], n, k;

// 求最长不上升子序列长度的二分
// ends[0...len-1]是降序的，找到<num的最左位置
// 不存在返回-1
int bs1(int len, int num) {
    int mid, l = 0, r = len - 1, ans = -1;
    while (l <= r) {
        mid = l + r >> 1;
        if (endss[mid] < num) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

// 求最长不下降子序列长度的二分
// ends[0...len-1]是升序的，找到>num的最左位置
// 不存在返回-1
int bs2(int len, int num) {
    int mid, l = 0, r = len - 1, ans = -1;
    while (l <= r) {
        mid = l + r >> 1;
        if (endss[mid] > num) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

void right() {
    int len = 0;
    for (int i = n - 1; i >= 0; i--) {
        int find = bs1(len, arr[i]);
        if (find == -1) {
            endss[len++] = arr[i];
            rights[i] = len;
        }
        else {
            endss[find] = arr[i];
            rights[i] = find + 1;
        }
    }
}

int compute() {
    right();
    int len = 0;
    int ans = 0;
    for (int i = 0, j = k, find, left; j < n; i++, j++) {
        find = bs2(len, arr[j]);
        left = find == -1 ? len : find;
        ans = max(ans, left + k + rights[j]);
        find = bs2(len, arr[i]);
        if (find == -1) {
            endss[len++] = arr[i];
        }
        else {
            endss[find] = arr[i];
        }
    }
    ans = max(ans, len + k);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << compute();
    return 0;
}