#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int deque_[N][2];
int h, t;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        h = t = 0;
        int ans = INT_MIN;
        for (int i = 0, x, y; i < n; i++) {
            x = points[i][0], y = points[i][1];
            while (h < t && deque_[h][0] + k < x) {
                h++;
            }
            if (h < t) {
                ans = max(ans, x + y + deque_[h][1] - deque_[h][0]);
            }
            while (h < t && deque_[t - 1][1] - deque_[t - 1][0] <= y - x) {
                t--;
            }
            deque_[t][0] = x;
            deque_[t++][1] = y;
        }
        return ans;
    }
};

int main() {
    return 0;
}