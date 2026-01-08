#include <bits/stdc++.h>
using namespace std;



//左神的方法更好，直接再定义一个str[N]数组，将s串对应到str
//数组中的0 ~ 4的数字串比我写get方法更自然
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int cnts[4];
        int debt = 0;
        for (int i = 0; i < n; i++) {
             int c = get(s[i]);
             cnts[c]++;
        }
        for (int i = 0; i < 4; i++) {
            if (cnts[i] < n / 4) {
                cnts[i] = 0;
            }
            else {
                cnts[i] = n / 4 - cnts[i];
                debt -= cnts[i];
            }
        }
        if (debt == 0) {
            return 0;
        }   
        int ans = INT_MAX;
        for (int l = 0, r = 0; r < n; r++) {
            if (cnts[get(s[r])]++ < 0) {
                debt--;
            }
            if (debt == 0) {
                while (cnts[get(s[l])] > 0) {
                    cnts[get(s[l])]--;
                    l++;
                }
                ans = min(ans, r - l + 1);
            }
        }
        return ans;
    }
    int get(char c) {
        int res = 0;
        if (c == 'Q') res = 0;
        else if (c == 'W') res = 1;
        else if (c == 'E') res = 2;
        else res = 3;
        return res;
    }
};