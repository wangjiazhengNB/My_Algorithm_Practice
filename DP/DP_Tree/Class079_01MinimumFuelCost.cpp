#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        for (auto& r : roads) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }
        vector<int> size(n);
        vector<long long> cost(n);
        f(graph, seats, 0, -1, size, cost);
        return cost[0];
    }
    void f(auto& graph, int seats, int u, int p, vector<int>& size, vector<long long>& cost) {
        size[u] = 1;
        for (int v : graph[u]) {
            if (v != p) {
                f(graph, seats, v, u, size, cost);
                size[u] += size[v];
                cost[u] += cost[v];
                cost[u] += (size[v] + seats - 1) / seats;
            }
        }
    }
};

int main() {
    return 0;
}