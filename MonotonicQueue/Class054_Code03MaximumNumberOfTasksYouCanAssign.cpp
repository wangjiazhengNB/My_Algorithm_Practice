#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int deque_[N];
vector<int> tasks;
vector<int> workers;
int h, t;

class Solution {
public:
    int maxTaskAssign(vector<int>& ts, vector<int>& ws, int pills, int strength) {
        tasks = ts, workers = ws;
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int tsize = tasks.size(), wsize = workers.size();
        int ans = 0;
        for (int l = 0, r = min(tsize, wsize), m; l <= r;) {
            m = (l + r) >> 1;
            if (f(0, m - 1, wsize - m, wsize - 1, strength, pills)) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;
    }
    bool f(int tl, int tr, int wl, int wr, int s, int pills) {
        h = t = 0;
        int cnt = 0;
        for (int i = wl, j = tl; i <= wr; i++) {
            for (; j <= tr && tasks[j] <= workers[i]; j++) {
                deque_[t++] = j;
            }
            if (h < t && tasks[deque_[h]] <= workers[i]) {
                h++;
            }
            else {
                for (; j <= tr && tasks[j] <= workers[i] + s; j++) {
                    deque_[t++] = j;
                }
                if (h < t) {
                    cnt++;
                    t--;
                }
                else {
                    return false;
                }
            }
        }
        return cnt <= pills;
    }
};

int main() {
    return 0;
}