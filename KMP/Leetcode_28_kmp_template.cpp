#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextArr(string &s, vector<int> &next, int m) {
        if (m == 1) {
            next[0] = -1;
            return ;
        }
        next[0] = -1, next[1] = 0;
        int i = 2, cn = 0;
        while (i < m) {
            if (s[i - 1] == s[cn]) {
                next[i++] = ++cn;
            }
            else if (cn > 0) {
                cn = next[cn];
            }
            else {
                next[i++] = 0;
            } 
        }
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> next(m, 0);
        nextArr(needle, next, m);
        int x = 0, y = 0;
        while (x < n && y < m) {
            if (haystack[x] == needle[y]) {
                x++;
                y++;
            }
            else if (y == 0) {
                x++;
            }
            else {
                y = next[y];
            }
        }
        return y == m ? x - y : -1;
    }
};

int main() {
    return 0;
}