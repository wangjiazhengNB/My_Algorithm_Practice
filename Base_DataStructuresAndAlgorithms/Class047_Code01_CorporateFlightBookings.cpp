#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cnt(n + 2);
        for (vector<int>& book : bookings) {
            cnt[book[0]] += book[2];
            cnt[book[1] + 1] -= book[2];
        }
        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = cnt[i + 1];
        return ans;
    }
};

int main() {
    return 0;
}