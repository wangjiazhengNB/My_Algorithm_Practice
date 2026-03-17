/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // 定义信息结构体：对应Java的Info类
    struct Info {
        int diameter;  // 以当前节点为根的子树的最大直径
        int height;    // 以当前节点为根的子树的高度

        // 构造函数：初始化直径和高度
        Info(int d, int h) : diameter(d), height(h) {}
    };

    // 递归遍历函数：后序遍历，收集左右子树信息
    Info f(TreeNode* x) {
        // 空节点：直径0，高度0
        if (x == nullptr) {
            return Info(0, 0);
        }

        // 递归获取左、右子树的信息
        Info leftInfo = f(x->left);
        Info rightInfo = f(x->right);

        // 计算当前节点的高度：左右子树最大高度 + 1
        int height = max(leftInfo.height, rightInfo.height) + 1;

        // 计算当前子树的直径：取三者最大值
        // 1. 左子树直径 2. 右子树直径 3. 左高度+右高度（经过当前根节点的路径）
        int diameter = max(max(leftInfo.diameter, rightInfo.diameter), leftInfo.height + rightInfo.height);

        // 返回当前节点的信息
        return Info(diameter, height);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 根节点的直径就是整棵树的直径
        return f(root).diameter;
    }
};