#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int N = 100010;
int dfn[N], deep[N], sizes[N], maxl[N], maxr[N];
int dfnCnt;

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfnCnt = 0;
        f(root, 0);
        for (int i = 1; i <= dfnCnt; i++) {
            maxl[i] = max(maxl[i - 1], deep[i]);
        }
        maxr[dfnCnt + 1] = 0;
        for (int i = dfnCnt; i >= 1; i--) {
            maxr[i] = max(maxr[i + 1], deep[i]);
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int leftMax = maxl[dfn[queries[i]] - 1];
            int rightMax = maxr[dfn[queries[i]] + sizes[dfn[queries[i]]]];
            ans[i] = max(leftMax, rightMax);
        }
        return ans;
    }
    void f(TreeNode* x, int k) {
        int i = ++dfnCnt;
        dfn[x->val] = i;
        deep[i] = k;
        sizes[i] = 1;
        if (x->left != nullptr) {
            f(x->left, k + 1);
            sizes[i] += sizes[dfn[x->left->val]];
        }
        if (x->right != nullptr) {
            f(x->right, k + 1);
            sizes[i] += sizes[dfn[x->right->val]];
        }
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    vector<int> queries = {2};
    Solution sol;
    vector<int> result = sol.treeQueries(root, queries);
    for (int num : result) {
        cout << num << endl;
    }
    deleteTree(root);
    return 0;
}