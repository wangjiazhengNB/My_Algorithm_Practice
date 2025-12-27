#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        for (int i = 0, cur = -50001; i < n; i++) {
            if (intervals[i][0] >= cur) {
                cur = intervals[i][1];
                ans++;
            }
        }
        return n - ans;
    }
};

int main() {
    return 0;
}