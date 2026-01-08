#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int cnts[256];
        int ans = 0;
        for (int require = 1; require <= 26; require++) {
            memset(cnts, 0, sizeof cnts);
            for (int l = 0, r = 0, collect = 0, satisfy = 0; r < n; r++) {
                if (++cnts[s[r]] == 1) {
                    collect++;
                }
                if (cnts[s[r]] == k) {
                    satisfy++;
                }
                while (collect > require) {
                    if (cnts[s[l]] == 1) {
                        collect--;
                    }
                    if (cnts[s[l]] == k) {
                        satisfy--;
                    }
                    cnts[s[l++]]--;
                }
                if (satisfy == require) {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
    }
};


int main() {
    return 0;
}