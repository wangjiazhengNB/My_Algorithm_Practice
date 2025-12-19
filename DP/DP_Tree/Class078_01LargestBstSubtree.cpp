#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Code01_LargestBstSubtree {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v = 0) : val(v), left(nullptr), right(nullptr) {}
    };

    struct Info {
        ll max_val;
        ll min_val;
        bool isBst;
        int maxBstSize;
        Info(ll a, ll b, bool c, int d)
        : max_val(a), min_val(b), isBst(c), maxBstSize(d) {}
    };

    static int largestBSTSubtree(TreeNode* root) {
        return f(root).maxBstSize;
    }

    static Info f(TreeNode* x) {
        if (x == nullptr) {
            return Info(LLONG_MIN, LLONG_MAX, true, 0);
        }
        Info infol = f(x->left);
        Info infor = f(x->right);
        ll max_val = max((ll)x->val, max(infol.max_val, infor.max_val));
        ll min_val = min((ll)x->val, min(infol.min_val, infor.min_val));
        bool isBst = infol.isBst && infor.isBst && (infol.max_val < x->val) && (x->val < infor.min_val);
        int maxBstSize;
        if (isBst) {
            // 当前子树是BST：大小=左BST大小+右BST大小+当前节点
            maxBstSize = infol.maxBstSize + infor.maxBstSize + 1;
        } else {
            // 当前子树不是BST：取左右子树中最大的BST大小
            maxBstSize = max(infol.maxBstSize, infor.maxBstSize);
        }
        return Info(max_val, min_val, isBst, maxBstSize);
    }

};

// 测试示例（可选，用于验证逻辑）
int main() {
    // 构建测试二叉树：
    //        10
    //       /  \
    //      5   15
    //     / \    \
    //    1   8    7
    Code01_LargestBstSubtree::TreeNode* root = new Code01_LargestBstSubtree::TreeNode(10);
    root->left = new Code01_LargestBstSubtree::TreeNode(5);
    root->right = new Code01_LargestBstSubtree::TreeNode(15);
    root->left->left = new Code01_LargestBstSubtree::TreeNode(1);
    root->left->right = new Code01_LargestBstSubtree::TreeNode(8);
    root->right->right = new Code01_LargestBstSubtree::TreeNode(7);

    // 预期输出：3（子树5->1/8的大小）
    cout << "最大BST子树大小：" << Code01_LargestBstSubtree::largestBSTSubtree(root) << endl;

    // 释放内存（避免内存泄漏）
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}