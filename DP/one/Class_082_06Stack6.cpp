#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        vector<int> prepare(n), done(n);
        prepare[1] = max(-prices[0], -prices[1]);
        done[1] = max(0, prices[1] - prices[0]);
        for (int i = 2; i < n; i++) {
            done[i] = max(done[i - 1], prepare[i - 1] + prices[i]);
            prepare[i] = max(prepare[i - 1], done[i - 2] - prices[i]);
        }
        return done[n - 1];
    }
};

int main() {
    return 0;
}