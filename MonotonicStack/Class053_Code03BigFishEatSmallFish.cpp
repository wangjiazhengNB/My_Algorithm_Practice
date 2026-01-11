#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int s[N][2];
int r;

class Solution {
public:
    int totalSteps(vector<int>& arr) {
        r = 0;
        int ans = 0;
        for (int i = arr.size() - 1, curTurns; i >= 0; i--) {
            curTurns = 0;
            while (r > 0 && s[r - 1][0] > arr[i]) {
                curTurns = max(curTurns + 1, s[--r][1]);
            }
            s[r][0] = arr[i];
            s[r][1] = curTurns;
            ans = max(ans, curTurns);
        }
        return ans;
    }
};

