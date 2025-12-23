#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mins = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            mins = min(mins, prices[i]);
            ans = max(ans, prices[i] - mins);
        }
        return ans;
    }
};

int main() {
    return 0;
}