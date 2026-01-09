#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int arr[N];
int stack_[N];
int ans[N][2];

int n, r;

void compute() {
    r = 0;
    int cur;
    //遍历阶段
    for (int i = 0; i < n; i++) {
        while (r > 0 && arr[stack_[r - 1]] >= arr[i]) {
            cur = stack_[--r];
            ans[cur][0] = r > 0 ? stack_[r - 1] : -1;
            ans[cur][1] = i;
        }
        stack_[r++] = i;
    }
    //清算阶段
    while (r > 0) {
        cur = stack_[--r];
        ans[cur][0] = r > 0 ? stack_[r - 1] : -1;
        ans[cur][1] = -1;
    }
    //修正阶段
    for (int i = n - 2; i >= 0; i--) {
        if (ans[i][1] != -1 && arr[ans[i][1]] == arr[i]) {
            ans[i][1] = ans[ans[i][1]][1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        compute();
        for (int i = 0; i < n; i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
    return 0;
}