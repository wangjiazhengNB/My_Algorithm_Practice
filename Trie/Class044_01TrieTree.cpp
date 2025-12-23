#include <bits/stdc++.h>
using namespace std;

class Code01_TrieTree {
public:
    class Trie1 {
    public:
        class TrieNode {
        public:
            int pass;
            int end;
            TrieNode* nexts[26];

            // 构造函数：初始化pass/end，nexts数组全为nullptr
            TrieNode() : pass(0), end(0) {
                for (int i = 0; i < 26; i++) {
                    nexts[i] = nullptr;
                }
            }
        };
    private:
        TrieNode* root;
    public:
        // 构造函数：初始化根节点
        Trie1() {
            root = new TrieNode();
        }

        //查询单词出现次数
        int countWordsEqualTo(const string& word) {
            TrieNode* node = root;
            for (int i = 0; i < word.size(); i++) {
                int path = word[i] - 'a';
                if (node->nexts[path] == nullptr) {
                    return 0;
                }
                node = node->nexts[path];
            }
            return node->end;
        }

        // 查询以pre为前缀的单词数
        int countWordsStartingWith(const string& pre) {
            TrieNode* node = root;
            for (int i = 0; i < pre.size(); i++) {
                int path = pre[i] - 'a';
                if (node->nexts[path] == nullptr) {
                    return 0;
                }
                node = node->nexts[path];
            }
            return node->pass;
        }

        // 插入单词
        void insert(const string& word) {
            TrieNode* node = root;
            node->pass++;
            for (int i = 0; i < word.size(); i++) {
                int path = word[i] - 'a';
                if (node->nexts[path] == nullptr) {
                    node->nexts[path] = new TrieNode();
                }
                node = node->nexts[path];
                node->pass++;
            }
            node->end++;
        }

        // 删除单词（仅当单词存在时）
        void erase(const string& word) {
            if (countWordsEqualTo(word) > 0) {
                TrieNode* node = root;
                node->pass--;
                for (int i = 0; i < word.size(); i++) {
                    int path = word[i] - 'a';
                    TrieNode* nextNode = node->nexts[path];
                    if (--nextNode->pass == 0) {
                        delete nextNode;
                        node->nexts[path] = nullptr;
                        return;
                    }
                    node = nextNode;
                }
                node->end--;
            }
        }

        static void deleteNode(TrieNode* node) {
            if (!node) return;
            for (int i = 0; i < 26; i++) {
                deleteNode(node->nexts[i]);
            }
            delete node;
        }

        // 析构函数：递归释放内存（避免内存泄漏，Java依赖GC，C++手动释放）
        ~Trie1() {
            deleteNode(root);
        }
    };

    // 哈希表实现的前缀树（Trie2），与Java Trie2逻辑完全一致
    class Trie2 {
    public:
        // 嵌套节点类，对应Java的TrieNode
        class TrieNode {
        public:
            int pass;   // 经过该节点的单词数
            int end;    // 以该节点为结尾的单词数
            unordered_map<int, TrieNode*> nexts; // 路径：key=字符ASCII值，value=子节点

            // 构造函数：初始化pass/end，哈希表为空
            TrieNode() : pass(0), end(0) {}
        };

    private:
        TrieNode* root; // 根节点

    public:
        // 构造函数：初始化根节点
        Trie2() {
            root = new TrieNode();
        }

        // 插入单词，逻辑与Java完全一致
        void insert(const string& word) {
            TrieNode* node = root;
            node->pass++; // 根节点pass先+1
            for (int i = 0; i < word.size(); ++i) {
                int path = static_cast<int>(word[i]); // 字符转ASCII值作为路径（对应Java的charAt(i)的int值）
                if (node->nexts.find(path) == node->nexts.end()) { // 路径不存在则新建节点
                    node->nexts[path] = new TrieNode();
                }
                node = node->nexts[path];
                node->pass++;
            }
            node->end++; // 最后一个节点end+1
        }

        // 删除单词（仅当单词存在时），逻辑与Java完全一致
        void erase(const string& word) {
            if (countWordsEqualTo(word) > 0) { // 先检查单词是否存在
                TrieNode* node = root;
                node->pass--;
                for (int i = 0; i < word.size(); ++i) {
                    int path = static_cast<int>(word[i]);
                    auto it = node->nexts.find(path);
                    if (it == node->nexts.end()) {
                        return; // 理论上不会触发，因已检查单词存在
                    }
                    TrieNode* nextNode = it->second;
                    if (--nextNode->pass == 0) { // pass减到0，删除节点并从哈希表移除
                        delete nextNode;
                        node->nexts.erase(it);
                        return; // 后续节点无需处理
                    }
                    node = nextNode;
                }
                node->end--; // 最后一个节点end-1
            }
        }

        // 查询单词出现次数，逻辑与Java完全一致
        int countWordsEqualTo(const string& word) {
            TrieNode* node = root;
            for (int i = 0; i < word.size(); ++i) {
                int path = static_cast<int>(word[i]);
                if (node->nexts.find(path) == node->nexts.end()) {
                    return 0; // 路径不存在，单词未插入
                }
                node = node->nexts[path];
            }
            return node->end; // 返回结尾节点的end值
        }

        // 查询以pre为前缀的单词数，逻辑与Java完全一致
        int countWordsStartingWith(const string& pre) {
            TrieNode* node = root;
            for (int i = 0; i < pre.size(); ++i) {
                int path = static_cast<int>(pre[i]);
                if (node->nexts.find(path) == node->nexts.end()) {
                    return 0; // 前缀路径不存在
                }
                node = node->nexts[path];
            }
            return node->pass; // 返回最后一个节点的pass值
        }

        // 析构函数：递归释放内存（避免内存泄漏）
        ~Trie2() {
            auto deleteNode = [](auto&& self, TrieNode* node) -> void {
                if (!node) return;
                for (auto& pair : node->nexts) {
                    self(self, pair.second);
                }
                delete node;
            };
            deleteNode(deleteNode, root);
        }
    };
};

// 可选：测试代码（验证逻辑正确性）
int main() {
    // 测试数组实现的Trie1
    Code01_TrieTree::Trie1 trie1;
    trie1.insert("apple");
    trie1.insert("apple");
    cout << trie1.countWordsEqualTo("apple") << endl; // 输出2
    cout << trie1.countWordsStartingWith("app") << endl; // 输出2
    trie1.erase("apple");
    cout << trie1.countWordsEqualTo("apple") << endl; // 输出1
    cout << trie1.countWordsStartingWith("app") << endl; // 输出1
    trie1.erase("apple");
    cout << trie1.countWordsEqualTo("apple") << endl; // 输出0
    cout << trie1.countWordsStartingWith("app") << endl; // 输出0

    // 测试哈希表实现的Trie2
    Code01_TrieTree::Trie2 trie2;
    trie2.insert("banana");
    trie2.insert("banana");
    cout << trie2.countWordsEqualTo("banana") << endl; // 输出2
    cout << trie2.countWordsStartingWith("ban") << endl; // 输出2
    trie2.erase("banana");
    cout << trie2.countWordsEqualTo("banana") << endl; // 输出1

    return 0;
}