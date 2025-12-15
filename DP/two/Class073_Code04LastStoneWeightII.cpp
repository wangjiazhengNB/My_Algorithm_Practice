#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto stone : stones) {
            sum += stone;
        }
        int near = f(stones, sum / 2);
        return sum - near - near;
    }
    int f(vector<int>& stones, int t) {
        vector<int> dp(t + 1);
        for (int stone : stones) {
            for (int j = t; j >= stone; j--) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }  
        return dp[t];
    }
};

int main() {
    return 0;
}