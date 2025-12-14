#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //最长递归子序列做法:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int len = 0;
        vector<int> ends(n);
        for (int i = 0; i < n; i++) {
            int find = bs(ends, len, pairs[i][0]);
            if (find == -1) {
                ends[len++] = pairs[i][1];
            }
            else {
                ends[find] = min(ends[find], pairs[i][1]);
            }
        }
        return len;
    }
    int bs(vector<int>& ends, int len, int num) {
        int mid, l = 0, r = len - 1, ans = -1;
        while (l <= r) {
            mid = l + r >> 1;
            if (ends[mid] >= num) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    //贪心做法
    int findLongestChain2(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int pre = INT_MIN;
        int ans = 0;
        for (auto pair : pairs) {
            if (pre < pair[0]) {
                pre = pair[1];
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}