#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 30001;

int father[MAXN];
int maxcnt[MAXN];

void build(int n) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
        maxcnt[i] = 1;
    }
}

int find(int i) {
    if (i != father[i]) {
        father[i] = find(father[i]);
    }
    return father[i];
}

int unionSet(int x, int y, vector<int>& vals) {
    int fx = find(x);
    int fy = find(y);
    int path = 0;
    if (vals[fx] > vals[fy]) {
        father[fy] = fx;
    } else if (vals[fx] < vals[fy]) {
        father[fx] = fy;
    } else {
        path = maxcnt[fx] * maxcnt[fy];
        father[fy] = fx;
        maxcnt[fx] += maxcnt[fy];
    }
    return path;
}

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        build(n);
        int ans = n;
        // 修正排序逻辑：等价于Java的升序规则
        sort(edges.begin(), edges.end(), [&vals](const vector<int>& e1, const vector<int>& e2) {
            int max1 = max(vals[e1[0]], vals[e1[1]]);
            int max2 = max(vals[e2[0]], vals[e2[1]]);
            return max1 < max2; // 关键修正：用<表示升序，与Java逻辑完全一致
        });
        for (vector<int>& edge : edges) {
            ans += unionSet(edge[0], edge[1], vals);
        }
        return ans;
    }
};

int main() {
    return 0;
}