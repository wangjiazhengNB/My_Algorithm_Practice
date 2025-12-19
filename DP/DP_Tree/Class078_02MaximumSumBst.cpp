#include <bits/stdc++.h>
using namespace std;

// 二叉搜索子树的最大键值和
class Code02_MaximumSumBst {
public:
  
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v = 0) : val(v), left(nullptr), right(nullptr) {}
    };

    struct Info {
        int max_val;    // 当前子树的最大值
        int min_val;    // 当前子树的最小值
        int sum;        // 当前子树的所有节点值之和
        bool isBst;     // 当前子树是否是BST
        int maxBstSum;  // 当前子树中BST子树的最大键值和

        Info(int a, int b, int c, bool d, int e)
            : max_val(a), min_val(b), sum(c), isBst(d), maxBstSum(e) {}
    };

    static int maxSumBST(TreeNode* root) {
        return f(root).maxBstSum;
    }

private:
   
    static Info f(TreeNode* x) {
        if (x == nullptr) {
            
            return Info(INT_MIN, INT_MAX, 0, true, 0);
        }
       
        Info infol = f(x->left);
        Info infor = f(x->right);

      
        int max_val = max(x->val, max(infol.max_val, infor.max_val));
      
        int min_val = min(x->val, min(infol.min_val, infor.min_val));
       
        int sum = infol.sum + infor.sum + x->val;
       
        bool isBst = infol.isBst && infor.isBst && (infol.max_val < x->val) && (x->val < infor.min_val);
       
        int maxBstSum = max(infol.maxBstSum, infor.maxBstSum);
      
        if (isBst) {
            maxBstSum = max(maxBstSum, sum);
        }

        // 返回当前节点的Info
        return Info(max_val, min_val, sum, isBst, maxBstSum);
    }
};

// 测试示例（验证逻辑正确性）
int main() {
    // 构建测试二叉树：
    //        1
    //       / \
    //      4   3
    //     / \   \
    //    2   5   6
    // 其中BST子树：4->2/5（和为11）、3->6（和为9）、1整体不是BST
    // 预期输出：11
    Code02_MaximumSumBst::TreeNode* root = new Code02_MaximumSumBst::TreeNode(1);
    root->left = new Code02_MaximumSumBst::TreeNode(4);
    root->right = new Code02_MaximumSumBst::TreeNode(3);
    root->left->left = new Code02_MaximumSumBst::TreeNode(2);
    root->left->right = new Code02_MaximumSumBst::TreeNode(5);
    root->right->right = new Code02_MaximumSumBst::TreeNode(6);
    cout << "二叉搜索子树的最大键值和：" << Code02_MaximumSumBst::maxSumBST(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}