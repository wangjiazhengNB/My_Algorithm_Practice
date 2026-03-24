#include <iostream>
using namespace std;

// 这道题就考一个double的精度误差问题
// 我掉坑里了，要用int算

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k;
    cin >> k;
    while (k--) {
        int mu, sigma, n;
        cin >> mu >> sigma >> n;
        int delta = n - mu;
        int z_times_100 = delta * 100 / sigma; // 整数运算，无精度误差
        int row = (z_times_100 / 10) + 1;      // 行号：Z*10 取整 +1
        int col = (z_times_100 % 10) + 1;     // 列号：Z*100 取个位 +1
        cout << row << " " << col << '\n';
    }
    return 0;
}