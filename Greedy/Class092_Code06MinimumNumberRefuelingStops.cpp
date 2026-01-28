#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) {
            return 0;
        }
        priority_queue<int, vector<int>, less<int>> heap;
        int to = startFuel;
        int cnt = 0;
        for (vector<int>& station : stations) {
            int position = station[0];
            int fuel = station[1];
            if (to < position) {
                while (!heap.empty() && to < position) {
                    to += heap.top();
                    heap.pop();
                    cnt++;
                    if (to >= target) {
                        return cnt;
                    }
                }
            }
            if (to < position) return -1;
            heap.push(fuel);
        }
        if (to < target) {
            while (!heap.empty()) {
                to += heap.top();
                heap.pop();
                cnt++;
                if (to >= target) {
                    return cnt;
                }
            } 
        }
        return -1;
    }
};

int main() {
    return 0;
}