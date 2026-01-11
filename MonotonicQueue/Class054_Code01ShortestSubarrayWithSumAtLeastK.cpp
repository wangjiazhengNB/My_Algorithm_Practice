#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int N = 100005;

ll sum[N];
int deque_[N];
int h, t;

class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        h = 0, t = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + arr[i];
        }
        int ans = INT_MAX;
        for (int l = 0; l <= n; l++) {
            while (h < t && sum[l] - sum[deque_[h]] >= k) {
                ans = min(ans, l - deque_[h++]);
            }
            while (h < t && sum[l] <= sum[deque_[t - 1]]) {
                t--;
            }
            deque_[t++] = l;
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main() {
    return 0;
}