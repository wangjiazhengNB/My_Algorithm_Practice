#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int maxDeque[N], minDeque[N];
int maxh, maxt, minh, mint;

vector<int> arr;


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        maxh = maxt = minh = mint = 0;
        arr = nums;
        int n = nums.size();
        int ans = 0;
        for (int l = 0, r = 0; l < n; l++) {
            while (r < n && ok(limit, arr[r])) {
                push(r++);
            }
            ans = max(ans, r - l);
            pop(l);
        }
        return ans;
    }
    bool ok(int limit, int number) {
        int max_val = maxh < maxt ? max(arr[maxDeque[maxh]], number) : number;
        int min_val = minh < mint ? min(arr[minDeque[minh]], number) : number;
        return max_val - min_val <= limit;
    }
    void push(int i) {
        while (maxh < maxt && arr[maxDeque[maxt - 1]] <= arr[i]) {
            maxt--;
        }
        maxDeque[maxt++] = i;
        while (minh < mint && arr[minDeque[mint - 1]] >= arr[i]) {
            mint--;
        }
        minDeque[mint++] = i;
    }
    void pop(int i) {
        if (maxh < maxt && maxDeque[maxh] == i) {
            maxh++;
        }
        if (minh < mint && minDeque[minh] == i) {
            minh++;
        }
    }
};

int main() {
    return 0;
}