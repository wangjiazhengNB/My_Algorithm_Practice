#include <bits/stdc++.h>
using namespace std;

// 二叉树节点定义（保留原定义）
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans;
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> presum;
        ans = 0;
        presum[0] = 1;  // 初始化前缀和：0出现1次
        f(root, (long long)targetSum, 0, presum);
        return ans;
    }

    void f(TreeNode* x, long long targetSum, long long sum, unordered_map<long long, long long>& presum) {
        if (x != nullptr) {
            sum += x->val;  // 累加当前节点值，sum是long long避免溢出
            // 查找sum - targetSum的前缀和次数，累加到ans
            if (presum.find(sum - targetSum) != presum.end()) {
                ans += presum[sum - targetSum];
            } else {
                ans += 0;
            }
            presum[sum]++;  // 更新当前前缀和的计数
            // 递归遍历左右子树
            f(x->left, targetSum, sum, presum);
            f(x->right, targetSum, sum, presum);
            presum[sum]--;  // 回溯：撤销当前节点的前缀和计数
        }
    }
};

// 辅助函数：释放二叉树内存（避免内存泄漏）
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 主函数：程序入口，构造测试用例并运行
int main() {
    // 构造经典测试用例：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    // 预期输出：3（路径：5->3、5->2->1、-3->11）
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    Solution sol;
    int result = sol.pathSum(root, targetSum);

    // 输出结果
    cout << "目标和为 " << targetSum << " 的路径数量：" << result << endl;

    // 释放二叉树内存
    deleteTree(root);
    return 0;
}