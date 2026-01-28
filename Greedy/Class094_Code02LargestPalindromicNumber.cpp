#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.size();
        int cnts[58] = {0};
        for (char a : num) {
            cnts[(int)a]++;
        }
        string left;
        char mid = 0;
        for (char c = '9'; c >= '1'; c--) {
            if ((cnts[c] & 1) == 1 && mid == '\0') {
                mid = c;
            }
            int half = cnts[c] / 2;
            for (int i = 0; i < half; i++) {
                left += c;
            }
        }
        if (left.empty()) {
            if (mid == 0) {
                return "0";
            }
            else {
                return string(1, mid);
            }
        }
        int zero_half = cnts['0'] / 2;
        for (int i = 0; i < zero_half; i++) {
            left += '0';
        }
        if (mid == 0 && (cnts['0'] & 1) == 1) {
            mid = '0';
        }
        string right = left;
        reverse(right.begin(), right.end());
        string ans = left;
        if (mid != 0) {
            ans += mid;
        }
        ans += right;
        return ans;
    }
};

int main() {
    return 0;
}