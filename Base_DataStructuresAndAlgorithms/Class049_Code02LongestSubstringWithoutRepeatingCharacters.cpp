#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int last[256] = {0};
        memset(last, -1, sizeof last);
        int ans = 0;
        for (int r = 0, l = 0, len = 0; r < n; r++) {
            l = max(l, last[s[r]] + 1);
            ans = max(ans, r - l + 1);
            last[s[r]] = r;
        }
        return ans;
    }
};

int main() {
    return 0;
}