#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int cnts[N];
bool enter[N];
char stack_[N];
int r;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        r = 0;
        memset(cnts, 0, sizeof cnts);
        memset(enter, false, sizeof enter);
        for (char cha : s) {
            cnts[cha - 'a']++;
        }
        for (char cur : s) {
            if (!enter[cur - 'a']) {
                while (r > 0 && stack_[r - 1] > cur && cnts[stack_[r - 1] - 'a'] > 0) {
                    enter[stack_[r - 1] - 'a'] = false;
                    r--;
                }
                stack_[r++] = cur;
                enter[cur - 'a'] = true;
            }
            cnts[cur - 'a']--;
        }
        return string(stack_, r);
    }
};

int main() {
    return 0;
}