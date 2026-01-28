#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int sort_[N];
int treeMaxLen[N];
int treeMaxLenCnt[N];
int m;
int maxLen, maxLenCnt;

int lowbit(int i) {
    return i & -i;
}

void query(int i) {
    maxLen = 0;
    maxLenCnt = 0;
    while (i > 0) {
        if (maxLen == treeMaxLen[i]) {
            maxLenCnt += treeMaxLenCnt[i];
        }
        else if (maxLen < treeMaxLen[i]) {
            maxLen = treeMaxLen[i];
            maxLenCnt = treeMaxLenCnt[i];
        }
        i -= lowbit(i);
    }
}

void add(int i, int len, int cnt) {
    while (i <= m) {
        if (treeMaxLen[i] == len) {
            treeMaxLenCnt[i] += cnt;
        }
        else if (treeMaxLen[i] < len) {
            treeMaxLen[i] = len;
            treeMaxLenCnt[i] = cnt;
        }
        i += lowbit(i);
    }
}

int rank_(int v) {
    int ans = 0;
    int l = 1, r = m, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (sort_[mid] >= v) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            sort_[i] = nums[i - 1];
        }
        sort(sort_ + 1, sort_ + n + 1);
        m = 1;
        for (int i = 2; i <= n; i++) {
            if (sort_[m] != sort_[i]) {
                sort_[++m] = sort_[i];
            }
        }
        memset(treeMaxLen, 0, sizeof treeMaxLen);
        memset(treeMaxLenCnt, 0, sizeof treeMaxLenCnt);
        int i;
        for (int num : nums) {
            i = rank_(num);
            query(i - 1);
            if (maxLen == 0) {
                add(i, 1, 1);
            }
            else {
                add(i, maxLen + 1, maxLenCnt);
            }
        }
        query(m);
        return maxLenCnt;
    }
};

int main() {
    return 0;
}