#include <bits/stdc++.h>
using namespace std;

int where;

class Solution {
public:
    string decodeString(string s) {
        where = 0;
        return f(s, 0);
    }
    string f(string& s, int i) {
        string path;
        int cnt = 0;
        while (i < s.size() && s[i] !=  ']') {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                path += s[i];
                i++;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i] - '0';
                i++;
            }
            else {
                path += get(cnt, f(s, i + 1));
                i = where + 1;
                cnt = 0;
            }
        }
        where = i;
        return path;
    }
    string get(int cnt, const string& s) {
        string path;
        for (int i = 0; i < cnt; i++) {
            path += s;
        }
        return path;
    }
};

int main() {
    return 0;
}