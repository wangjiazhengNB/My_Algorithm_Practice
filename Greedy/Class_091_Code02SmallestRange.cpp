#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    int i;
    int j;
    //Node() = default;
    //Node(int a, int b, int c) : v(a), i(b), j(c) {}
}node;

struct cmp {
    bool operator()(const Node& a, const Node& b)const {
        if (a.v == b.v) return a.i < b.i;
        return a.v < b.v;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        set<Node, cmp> s;
        for (int i = 0; i < k; i++) {
            node = {nums[i][0], i, 0};
            s.insert(node);
        }
        int r = INT_MAX;
        int a = 0, b = 0;
        //Node max_node, min_node;
        while (s.size() == k) {
            //获取集合中值最大的元素
            Node max_node = *s.rbegin();
            //获取并删除集合中值最小的元素
            Node min_node = *s.begin();
            s.erase(s.begin());
            if (max_node.v - min_node.v < r) {
                r = max_node.v - min_node.v;
                a = min_node.v;
                b = max_node.v;
            }
            if (min_node.j + 1 < nums[min_node.i].size()) {
                s.insert(Node(nums[min_node.i][min_node.j + 1], min_node.i, min_node.j + 1));
            }
        }
        return {a, b};
    }
};

int main() {
    return 0;
}