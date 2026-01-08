#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
int cnts[N];


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return numsOfMostKinds(arr, k) - numsOfMostKinds(arr, k - 1);
    }
    int numsOfMostKinds(vector<int>& arr, int k) {
        int n = arr.size();
        memset(cnts, 0, sizeof cnts);
        int collect = 0;
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (++cnts[arr[r]] == 1) {
                collect++;
            }
            while (collect > k) {
                if (--cnts[arr[l++]] == 0) {
                    collect--;
                }
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}