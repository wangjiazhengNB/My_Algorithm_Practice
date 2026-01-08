#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); i++) {
            while (!best(houses, heaters, i, j)) {
                j++;
            }
            ans = max(ans, abs(heaters[j] - houses[i]));
        }
        return ans;
    }
    bool best(vector<int>& houses, vector<int>& heaters, int i, int j) {
        return j == heaters.size() - 1
            ||
            abs(heaters[j] - houses[i]) < abs(heaters[j + 1] - houses[i]);
    }
};

int main() {
    return 0;
}