#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> mp(32, -2);
        mp[0] = -1;
        int ans = 0;
        for (int i = 0, status = 0, m; i < n; i++) {
            m = move(s[i]);
            if (m != -1) {
                status ^= 1 << m;
            }
            if (mp[status] != -2) {
                ans = max(ans, i - mp[status]);
            }
            else {
                mp[status] = i;
            }
        }
        return ans;
    }
    int move(char c) {
        if (c == 'a') return 0;
        else if (c == 'e') return 1;
        else if (c == 'i') return 2;
        else if (c == 'o') return 3;
        else if (c == 'u') return 4;
        else return -1;
    }
};