#include <bits/stdc++.h>
using namespace std;

class BinaryTreeTraversalRecursion {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    // 递归基本样子，用来理解递归序
    static void f(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        // 1
        f(head->left);
        // 2
        f(head->right);
        //3
    }
    //先序
    static void preOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        cout << head->val << " ";
        preOrder(head->left);
        preOrder(head->right);
    }
    //中序
    static void inOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        inOrder(head->left);
        cout << head->val << " ";
        inOrder(head->right);
    }
    //后序
    static void posOrder(TreeNode* head) {
        if (head == nullptr) return;
        posOrder(head->left);
        posOrder(head->right);
        cout << head->val << " ";
    }
};

int main() {
    BinaryTreeTraversalRecursion::TreeNode* head = new BinaryTreeTraversalRecursion::TreeNode(1);
    head->left = new BinaryTreeTraversalRecursion::TreeNode(2);
    head->right = new BinaryTreeTraversalRecursion::TreeNode(3);
    head->left->left = new BinaryTreeTraversalRecursion::TreeNode(4);
    head->left->right = new BinaryTreeTraversalRecursion::TreeNode(5);
    head->right->left = new BinaryTreeTraversalRecursion::TreeNode(6);
    head->right->right = new BinaryTreeTraversalRecursion::TreeNode(7);
    // 先序遍历
    BinaryTreeTraversalRecursion::preOrder(head);
    cout << endl;
    cout << "先序遍历递归版" << endl;

    // 中序遍历
    BinaryTreeTraversalRecursion::inOrder(head);
    cout << endl;
    cout << "中序遍历递归版" << endl;

    // 后序遍历
    BinaryTreeTraversalRecursion::posOrder(head);
    cout << endl;
    cout << "后序遍历递归版" << endl;

    // 释放内存（C++需要手动释放）
    delete head->left->left;
    delete head->left->right;
    delete head->right->left;
    delete head->right->right;
    delete head->left;
    delete head->right;
    delete head;
    return 0;
}