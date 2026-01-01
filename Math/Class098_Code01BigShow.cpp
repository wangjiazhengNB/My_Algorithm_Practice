#include <bits/stdc++.h>
using namespace std;

//矩阵相乘
vector<vector<int>> multiply(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b[0].size();
    int k = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < k; c++) {
                ans[i][j] += a[i][c] * b[c][j];
            }
        }
    }
}



int main() {

    return 0;
}