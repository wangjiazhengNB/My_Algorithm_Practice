#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int LIMIT = 16;

class TreeAncestor {
private:
    int power;
    int head[N];
    int ne[N];
    int to[N];
    int cnt;
    int deep[N];
    int stjump[N][LIMIT];

    int log2(int n) {
        int ans = 0;
        while ((1 << ans) <= (n >> 1)) {
            ans++;
        }
        return ans;
    }
    
    void add(int u, int v) {
        to[cnt] = v;
        ne[cnt] = head[u];
        head[u] = cnt++;
    }

    void dfs(int i, int f) {
        if (i == 0) {
            deep[i] = 1;
        }
        else {
            deep[i] = deep[f] + 1;
        }
        stjump[i][0] = f;
        for (int p = 1; p <= power; p++) {
            stjump[i][p] = stjump[stjump[i][p - 1]][p - 1];
        }
        for (int e = head[i]; e != 0; e = ne[e]) {
            dfs(to[e], i);
        }
    }

public:
    TreeAncestor(int n, vector<int>& parent) {
        power = log2(n);
        cnt = 1;
        memset(head, 0, sizeof head);
        for (int i = 1; i < parent.size(); i++) {
            add(parent[i], i);
        }
        dfs(0, 0);
    }
    
    int getKthAncestor(int i, int k) {
        if (deep[i] <= k) {
            return -1;
        }
        int s = deep[i] - k;
        for (int p = power; p >= 0; p--) {
            if (deep[stjump[i][p]] >= s) {
                i = stjump[i][p];
            }
        }
        return i;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */