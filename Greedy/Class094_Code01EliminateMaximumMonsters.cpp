#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(time.begin(), time.end());
        for (int i = 0; i < n; i++) {
            if (time[i] <= i) {
                return i;
            }
        }
        return n;
    }
};

int main() {
    return 0;
}