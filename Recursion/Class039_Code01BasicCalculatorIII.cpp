#include <bits/stdc++.h>
#include <string>
using namespace std;

int where;


class Solution {
public:
    int solve(string s) {
        where = 0;
        return f(s, 0);
    }
    int f(string& s, int i) {
        int cur = 0;
        vector<int> nums;
        vector<char> ops;
        while (i < s.size() && s[i] != ')') {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + s[i++] - '0';
            }
            else if (s[i] != '(') {
                push(nums, ops, cur, s[i++]);
                cur = 0;
            }
            else {
                cur = f(s, i + 1);
                i = where + 1;
            }
        }
        push(nums, ops, cur, '+');
        where = i;
        return compute(nums, ops);
    }
    void push(vector<int>& nums, vector<char>& ops, int cur, char op) {
        int n = nums.size();
        if (n == 0 || ops[n - 1] == '+' || ops[n - 1] == '-') {
            nums.push_back(cur);
            ops.push_back(op);
        }
        else {
            int toNum = nums[n - 1];
            char toOp = ops[n - 1];
            if (toOp == '*') {
                nums[n - 1] = toNum * cur;
                ops[n - 1] = op;
            }
            else {
                nums[n - 1] = toNum / cur;
                ops[n - 1] = op;
            }
        }
    }
    int compute(vector<int>& nums, vector<char>& ops) {
        int n = nums.size();
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            ans += (ops[i - 1] == '+') ? nums[i] : -nums[i];
        }
        return ans;
    }
};

int main() {
    return 0;
}







