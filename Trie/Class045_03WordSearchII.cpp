#include <bits/stdc++.h>
using namespace std;

const int N = 3000005;
int tree[N][26], pass[N], cnt = 1;
string end_[N];

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        cnt = 1;
        for (string word : words) {
            insert(word);
        }
        int n = board.size();
        int m = board[0].size();
        vector<string> ans;
        int t;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, 1, ans);
            }
        }
        clear();
        return ans;
    }
    void insert(string &word) {
        int cur = 1;
        pass[cur]++;
        for (int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if (tree[cur][path] == 0) {
                tree[cur][path] = ++cnt;
            }
            cur = tree[cur][path];
            pass[cur]++;
        }
        end_[cur] = word;
    }
    int dfs(auto& board, int i, int j, int t, vector<string>& ans) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == 0) {
            return 0;
        }
        char tmp = board[i][j];
        int road = tmp - 'a';
        t = tree[t][road];
        if (t == 0 || pass[t] == 0) {
            return 0;
        }
        int fix = 0;
        if (end_[t] != "") {
            ans.push_back(end_[t]);
            fix++;
            end_[t] = "";
        }
        board[i][j] = 0;
        fix += dfs(board, i - 1, j, t, ans);
        fix += dfs(board, i + 1, j, t, ans);
        fix += dfs(board, i, j - 1, t, ans);
        fix += dfs(board, i, j + 1, t, ans);
        pass[t] -= fix;
        board[i][j] = tmp;
        return fix;
    }
    void clear() {
        for (int i = 1; i <= cnt; i++) {
            memset(tree[i], 0, sizeof tree[i]);
            pass[i] = 0;
            end_[i] = "";
        }
        cnt = 1;
    }
};

int main() {
    return 0;
}