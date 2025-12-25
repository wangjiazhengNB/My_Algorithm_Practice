#include <bits/stdc++.h>
using namespace std;

const int N = 3000005;
int tree[N][2], cnt, high;


class Solution {
public:
    int findMaximumXOR1(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        build(nums);
        for (int i = 0; i < n; i++) {
            ans = max(ans, maxXor(nums[i]));
        }
        clear();
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int max_num = INT_MIN;
        unordered_set<int> set;
        for (int num : nums) {
            max_num = max(max_num, num);
        }
        if (max_num == 0) {
            high = -1;
        }
        else {
            int length = 0;
            for (int i = 31; i >= 0; i--) {
                if ((1 << i) & 1 == 0) length++;
                else break;
            }
            high = 31 - length;
        }
        int ans = 0;
        for (int i = high; i >= 0; i--) {
            int better = ans | (1 << i);
            set.clear();
            for (int num : nums) {
                int prefix = (num >> i) << i;
                set.insert(prefix);
                if (set.count(better ^ prefix)) {
                    ans = better;
                    break;
                }
            }
        }
        return ans;    
    }
    void build(vector<int>& nums) {
        cnt = 1;
        int maxs = INT_MIN;
        for (int num : nums) {
            maxs = max(maxs, num);
        }
        //这里是求前导0的长度
        if (maxs == 0) {
            high = -1;
        }
        else {
            int length = 0;
            for (int i = 31; i >= 0; i--) {
                if (((maxs >> i) & 1) == 0) length++;
                else break;
            }
            high = 31 - length;
        }
        for (int num : nums) {
            insert(num);
        }
    }

    void insert(int num) {
        int cur = 1;
        for (int i = high; i >= 0; i--) {
            int p = (num >> i) & 1;
            if (tree[cur][p] == 0) {
                tree[cur][p] = ++cnt;
            }
            cur = tree[cur][p];
        }
    }

    int maxXor(int num) {
        int ans = 0;
        int cur = 1;
        for (int i = high, status, want; i >= 0; i--) {
            status = (num >> i) & 1;
            want = status ^ 1;
            if (tree[cur][want] == 0) {
                want ^= 1;
            }
            ans |= (status ^ want) << i;
            cur = tree[cur][want];
        }
        return ans;
    }

    void clear() {
        for (int i = 1; i <= cnt; i++) {
            memset(tree[i], 0, sizeof tree[i]);
        }
        cnt = 1;
    }
};

int main() {
    return 0;
}