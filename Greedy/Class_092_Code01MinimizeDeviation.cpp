#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            if (num % 2 == 0) {
                s.insert(num);
            }
            else {
                s.insert(num * 2);
            }
        }
        int ans = *s.rbegin() - *s.begin();
        while (ans > 0 && *s.rbegin() % 2 == 0) {
            int max_val = *s.rbegin();
            s.erase(max_val);
            s.insert(max_val / 2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        return ans;
    }
};

int main() {
    return 0;
}