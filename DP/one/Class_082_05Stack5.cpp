#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int prepare = -prices[0] - fee;
        int done = 0;
        for (int i = 1; i < n; i++) {
            done = max(done, prepare + prices[i]);
            prepare = max(prepare, done - prices[i] - fee);
        }
        return done;
    }
};

int main() {
    return 0;
}