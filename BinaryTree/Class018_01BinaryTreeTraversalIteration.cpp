#include <bits/stdc++.h>
using namespace std;

// 不用递归，用迭代的方式实现二叉树的三序遍历
class BinaryTreeTraversalIteration {
public:
    // 定义二叉树节点结构体（对应Java的内部类）
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    // 先序打印所有节点，非递归版
    static void preOrder(TreeNode* head) {
        if (head != nullptr) {
            stack<TreeNode*> stk;
            stk.push(head);
            while (!stk.empty()) {
                head = stk.top();
                stk.pop();
                cout << head->val << " ";
                if (head->right != nullptr) {
                    stk.push(head->right);
                }
                if (head->left != nullptr) {
                    stk.push(head->left);
                }
            }
            cout << endl;
        }
    }

    // 中序打印所有节点，非递归版
    static void inOrder(TreeNode* head) {
        if (head != nullptr) {
            stack<TreeNode*> stk;
            while (!stk.empty() || head != nullptr) {
                if (head != nullptr) {
                    stk.push(head);
                    head = head->left;
                } else {
                    head = stk.top();
                    stk.pop();
                    cout << head->val << " ";
                    head = head->right;
                }
            }
            cout << endl;
        }
    }

    // 后序打印所有节点，非递归版（两个栈实现）
    static void posOrderTwoStacks(TreeNode* head) {
        if (head != nullptr) {
            stack<TreeNode*> stk;
            stack<TreeNode*> collect;
            stk.push(head);
            while (!stk.empty()) {
                head = stk.top();
                stk.pop();
                collect.push(head);
                if (head->left != nullptr) {
                    stk.push(head->left);
                }
                if (head->right != nullptr) {
                    stk.push(head->right);
                }
            }
            while (!collect.empty()) {
                cout << collect.top()->val << " ";
                collect.pop();
            }
            cout << endl;
        }
    }

    // 后序打印所有节点，非递归版（一个栈实现）
    static void posOrderOneStack(TreeNode* h) {
        if (h != nullptr) {
            stack<TreeNode*> stk;
            stk.push(h);
            // h的含义：上一次打印的节点（初始为头节点，未打印时保持）
            while (!stk.empty()) {
                TreeNode* cur = stk.top();
                if (cur->left != nullptr && h != cur->left && h != cur->right) {
                    // 有左树且左树未处理过
                    stk.push(cur->left);
                } else if (cur->right != nullptr && h != cur->right) {
                    // 有右树且右树未处理过
                    stk.push(cur->right);
                } else {
                    // 左/右树无或已处理，打印当前节点
                    cout << cur->val << " ";
                    h = stk.top();
                    stk.pop();
                }
            }
            cout << endl;
        }
    }

    // 用一个栈完成先序遍历（返回vector，对应LeetCode接口）
    static vector<int> preorderTraversal(TreeNode* head) {
        vector<int> ans;
        if (head != nullptr) {
            stack<TreeNode*> stk;
            stk.push(head);
            while (!stk.empty()) {
                head = stk.top();
                stk.pop();
                ans.push_back(head->val);
                if (head->right != nullptr) {
                    stk.push(head->right);
                }
                if (head->left != nullptr) {
                    stk.push(head->left);
                }
            }
        }
        return ans;
    }

    // 用一个栈完成中序遍历（返回vector，对应LeetCode接口）
    static vector<int> inorderTraversal(TreeNode* head) {
        vector<int> ans;
        if (head != nullptr) {
            stack<TreeNode*> stk;
            while (!stk.empty() || head != nullptr) {
                if (head != nullptr) {
                    stk.push(head);
                    head = head->left;
                } else {
                    head = stk.top();
                    stk.pop();
                    ans.push_back(head->val);
                    head = head->right;
                }
            }
        }
        return ans;
    }

    // 用两个栈完成后序遍历（返回vector，对应LeetCode接口）
    static vector<int> postorderTraversalTwoStacks(TreeNode* head) {
        vector<int> ans;
        if (head != nullptr) {
            stack<TreeNode*> stk;
            stack<TreeNode*> collect;
            stk.push(head);
            while (!stk.empty()) {
                head = stk.top();
                stk.pop();
                collect.push(head);
                if (head->left != nullptr) {
                    stk.push(head->left);
                }
                if (head->right != nullptr) {
                    stk.push(head->right);
                }
            }
            while (!collect.empty()) {
                ans.push_back(collect.top()->val);
                collect.pop();
            }
        }
        return ans;
    }

    // 用一个栈完成后序遍历（返回vector，对应LeetCode接口）
    static vector<int> postorderTraversalOneStack(TreeNode* h) {
        vector<int> ans;
        if (h != nullptr) {
            stack<TreeNode*> stk;
            stk.push(h);
            while (!stk.empty()) {
                TreeNode* cur = stk.top();
                if (cur->left != nullptr && h != cur->left && h != cur->right) {
                    stk.push(cur->left);
                } else if (cur->right != nullptr && h != cur->right) {
                    stk.push(cur->right);
                } else {
                    ans.push_back(cur->val);
                    h = stk.top();
                    stk.pop();
                }
            }
        }
        return ans;
    }
};

int main() {
    // 构建测试二叉树（与Java代码完全一致）
    BinaryTreeTraversalIteration::TreeNode* head = new BinaryTreeTraversalIteration::TreeNode(1);
    head->left = new BinaryTreeTraversalIteration::TreeNode(2);
    head->right = new BinaryTreeTraversalIteration::TreeNode(3);
    head->left->left = new BinaryTreeTraversalIteration::TreeNode(4);
    head->left->right = new BinaryTreeTraversalIteration::TreeNode(5);
    head->right->left = new BinaryTreeTraversalIteration::TreeNode(6);
    head->right->right = new BinaryTreeTraversalIteration::TreeNode(7);

    // 调用各遍历方法（打印版）
    BinaryTreeTraversalIteration::preOrder(head);
    cout << "先序遍历非递归版" << endl;

    BinaryTreeTraversalIteration::inOrder(head);
    cout << "中序遍历非递归版" << endl;

    BinaryTreeTraversalIteration::posOrderTwoStacks(head);
    cout << "后序遍历非递归版 - 2个栈实现" << endl;

    BinaryTreeTraversalIteration::posOrderOneStack(head);
    cout << "后序遍历非递归版 - 1个栈实现" << endl;

    // 可选：测试返回vector的版本（打印结果验证）
    vector<int> pre_ans = BinaryTreeTraversalIteration::preorderTraversal(head);
    cout << "先序遍历返回vector: ";
    for (int val : pre_ans) cout << val << " ";
    cout << endl;

    // 释放内存（C++手动管理，避免内存泄漏）
    delete head->left->left;
    delete head->left->right;
    delete head->right->left;
    delete head->right->right;
    delete head->left;
    delete head->right;
    delete head;

    return 0;
}