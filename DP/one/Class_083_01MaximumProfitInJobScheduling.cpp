#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int dp[N];

struct job {
    int start;
    int end;
    int profit;
    bool operator<(const job &C)const {
        return end < C.end;
    }
}jobs[N];


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        sort(jobs, jobs + n);
        dp[0] = jobs[0].profit;
        for (int i = 1, start; i < n; i++) {
            dp[i] = jobs[i].profit;
            start = jobs[i].start;
            if (jobs[0].end <= start) {
                dp[i] += dp[find(i - 1, start)];
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
    int find(int i, int start) {
        int l = 0, r = i, m;
        int ans = 0;
        while (l <= r) {
            m = l + r >> 1;
            if (jobs[m].end <= start) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}