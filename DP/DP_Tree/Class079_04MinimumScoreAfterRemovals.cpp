#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dfn[N], xors[N], sizes[N];
int dfnCnt;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        dfnCnt = 0;
        memset(dfn, 0, sizeof dfn);
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        } 
        int m = edges.size();
        f(nums, graph, 0);
        int ans = INT_MAX;
        for (int i = 0, a, b, pre, pos, sum1, sum2, sum3; i < m; i++) {
            a = max(dfn[edges[i][0]], dfn[edges[i][1]]);
            for (int j = i + 1; j < m; j++) {
                b = max(dfn[edges[j][0]], dfn[edges[j][1]]);
                if (a < b) {
                    pre = a;
                    pos = b;
                }
                else {
                    pre = b;
                    pos = a;
                }
                sum1 = xors[pos];
                if (pre + sizes[pre] > pos) {
                    sum2 = xors[pre] ^ xors[pos];
                    sum3 = xors[1] ^ xors[pre]; 
                }
                else {
                    sum2 = xors[pre];
                    sum3 = xors[1] ^ xors[pre] ^ xors[pos];
                }
                ans = min(ans, max(sum3, max(sum1, sum2)) - min(sum3, min(sum1, sum2)));
            }
        }
        return ans;
    }
    void f(vector<int>& nums, vector<vector<int>>& graph, int u) {
        //以dfn编号为下标
        int i = ++dfnCnt;
        dfn[u] = i;
        xors[i] = nums[u];
        sizes[i] = 1;
        for (int v : graph[u]) {
            if (dfn[v] == 0) {
                f(nums, graph, v);
                xors[i] ^= xors[dfn[v]];
                sizes[i] += sizes[dfn[v]];
            }
        }
    }
};

int main() {
    return 0;
}