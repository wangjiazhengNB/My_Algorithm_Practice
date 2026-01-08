#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int l = 0, r = n - 1;
        int ans = 0;
        while (l <= r) {
            int sum = l == r ? people[l] : people[l] + people[r];
            if (sum <= limit) {
                l++, r--;
                ans += 1;
            }
            else {
                r--;
                ans += 1;
            }
        }
        return ans;
    }
};