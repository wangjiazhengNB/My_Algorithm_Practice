#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
int tree[N][12];
int pass[N], cnt = 1;


class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param b int整型vector<vector<>>
     * @param a int整型vector<vector<>>
     * @return int整型vector
     */
    vector<int> countConsistentKeys(vector<vector<int> >& b,
                                    vector<vector<int> >& a) {
        cnt = 1;
        clear();
        string s;
        for (auto t : a) {
            s.clear();
            for (int i = 1; i < t.size(); i++) {
                s += to_string(t[i] - t[i - 1]) + '#';
            }
            insert(s);
        }

        vector<int> ans(b.size());

        for (int i = 0; i < b.size(); i++) {
            s.clear();
            for (int j = 1; j < b[i].size(); j++) {
                s += to_string(b[i][j] - b[i][j - 1]) + '#';
            }
            ans[i] = count(s);
        }
        return ans;
    }
    void insert(string s) {
        int cur = 1;
        pass[cur]++;
        for (int i = 0; i < s.size(); i++) {
            int p = path(s[i]);
            if (tree[cur][p] == 0) {
                tree[cur][p] = ++cnt;
            }
            cur = tree[cur][p];
            pass[cur]++;
        }
    }
    int count(string pre) {
        int cur = 1;
        for (int i = 0; i < pre.size(); i++) {
            int p = path(pre[i]);
            if (tree[cur][p] == 0) return 0;
            cur = tree[cur][p];
        }
        return pass[cur];
    }

    int path(char& c) {
        if (c == '#') return 10;
        else if (c == '-') return 11;
        else {
            return c - '0';
        }
    }
    void clear() {
        for (int i = 1; i <= cnt; i++) {
            memset(tree[i], 0, sizeof tree[i]);
            pass[i] = 0;
        }
        cnt = 1;
    }
};

int main() {
    reuturn 0;
}





