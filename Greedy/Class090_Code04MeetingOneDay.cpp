#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int max_num = events[0][1];
        int min_num = events[0][0];
        for (int i = 1; i < n; i++) {
            max_num = max(max_num, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<int>> heap;
        int i = 0, ans = 0;
        for (int day = min_num; day <= max_num; day++) {
            while (i < n && events[i][0] == day) {
                heap.push(events[i++][1]);
            }
            while (!heap.empty() && heap.top() < day) {
                heap.pop();
            }
            if (!heap.empty()) {
                heap.pop();
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}