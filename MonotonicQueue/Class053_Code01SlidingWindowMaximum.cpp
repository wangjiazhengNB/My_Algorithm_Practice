#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int deque_[N];
int h, t;



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        h = 0, t = 0;
        for (int i = 0; i < k - 1; i++) {
            while (h < t && arr[deque_[t - 1]] <= arr[i]) {
                t--;
            }
            deque_[t++] = i;
        }  
        int m = n - k + 1;
        vector<int> ans(m);
        for (int l = 0, r = k - 1; l < m; l++, r++) {
            while (h < t && arr[deque_[t - 1]] <= arr[r]) {
                t--;
            }
            deque_[t++] = r;
            ans[l] = arr[deque_[h]];
            if (deque_[h] == l) h++; 
        }
        return ans;
    }
};

int main() {
    return 0;
}