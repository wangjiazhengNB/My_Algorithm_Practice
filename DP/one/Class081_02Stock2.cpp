#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += max(prices[i + 1] - prices[i], 0);
        }
        return ans;
    }
};

int main() {
    return 0;
}