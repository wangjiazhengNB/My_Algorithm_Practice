#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
        }
        return f(s, graph, 0).maxPath;
    }
    struct Info {
        int maxPathFromHead;
        int maxPath;
        Info(int a, int b) : maxPathFromHead(a), maxPath(b) {} 
    };

    Info f(string& s, vector<vector<int>>& graph, int u) {
        if (graph[u].empty()) {
            return Info(1, 1);
        }
        int max1 = 0;
        int max2 = 0;
        int maxPath = 1;
        for (int v : graph[u]) {
            Info nextInfo = f(s, graph, v); 
            maxPath = max(maxPath, nextInfo.maxPath);
            if (s[u] != s[v]) {
                if (nextInfo.maxPathFromHead > max1) {
                    max2 = max1; 
                    max1 = nextInfo.maxPathFromHead;
                }
                else if (nextInfo.maxPathFromHead > max2) {
                    max2 = nextInfo.maxPathFromHead;
                }
            }
        }
        int maxPathFromHead = max1 + 1;
        maxPath = max(maxPath, max1 + max2 + 1);
        return Info(maxPathFromHead, maxPath);
    }
};

int main() {
    return 0;
}