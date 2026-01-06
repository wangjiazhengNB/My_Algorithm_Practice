#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int l = 0, r = 0; l < n; l = r + 1, r = l) {
            int sum = 0;
            while (sum + gas[r % n] - cost[r % n] >= 0) {
                if (r - l + 1 == n) {
                    return l;
                }
                sum += gas[r % n] - cost[r % n];
                r++;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}