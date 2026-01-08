#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int last[256] = {0};
        memset(last, 0, sizeof last);
        int debt = t.size();
        for (int i = 0; i < t.size(); i++) {
            last[t[i]]--;
        }
        int start = 0;
        int len = INT_MAX;-
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (last[s[r]]++ < 0) {
                debt--;
            }
            if (debt == 0) {
                while (last[s[l]] > 0) {
                    last[s[l++]]--;
                }
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    return 0;
}