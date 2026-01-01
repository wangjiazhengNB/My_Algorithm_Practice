#include <bits/stdc++.h>
using namespace std;

void swap(vector<vector<int>>& jobs, int i, int j) {
    vector<int> tmp;
    tmp = jobs[i];
    jobs[i] = jobs[j];
    jobs[j] = tmp;
}

int f1(vector<vector<int>>& jobs, int n, int i) {
    if (i == n) {
        int ans = 0; 
        for (auto& job : jobs) {
            ans = max(ans + job[0], job[1]);
        }
        return ans;
    }
    else {
        int ans = INT_MAX;
        for (int j = i; j < n; j++) {
            swap(jobs, i, j);
            ans = min(ans, f1(jobs, n, i + 1));
            swap(jobs, i, j);
        }
        return ans;
    }
}

int atLeast1(vector<vector<int>>& jobs) {
    int n = jobs.size();
    return f1(jobs, n, 0);
}

int atLeast2(vector<vector<int>>& jobs) {
    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
        return (b[0] - b[1]) < (a[0] - a[1]);
    });
    int ans = 0;
    for (int i = 0; i < jobs.size(); i++) {
        ans = max(ans + jobs[i][0], jobs[i][1]);
    }
    return ans;
}

vector<vector<int>> randomJobs(int n, int v) {
    vector<vector<int>> ans(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        ans[i][0] = rand() % v + 1;
        ans[i][1] = rand() % v + 1;
    }
    return ans;
}

int main() {
    srand((unsigned int)time(nullptr));
    int N = 10;
    int V = 20;
    int testTimes = 20;
    cout << "测试开始" << endl;
    for (int i = 1; i <= testTimes; i++) {
        int n = rand() % N + 1;
        vector<vector<int>> jobs = randomJobs(n, V);
        vector<vector<int>> jobs1 = jobs;
        vector<vector<int>> jobs2 = jobs;
        int ans1 = atLeast1(jobs);
        int ans2 = atLeast2(jobs);
        if (ans1 != ans2) {
            cout << "出错了" << endl;
        }
        if (i % 100 == 0) {
            cout << "测试到第" << i << "组" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}