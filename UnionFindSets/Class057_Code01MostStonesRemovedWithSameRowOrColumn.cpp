#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int father[N];
int sets;
unordered_map<int, int> rowFirst;
unordered_map<int, int> colFirst;

void build(int n) {
    rowFirst.clear();
    colFirst.clear();
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
    sets = n;
}

int find(int x) {
    if (father[x] != x) father[x] = find(father[x]);
    return father[x];
}
void union_(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        father[fx] = fy;
        sets--;
    }
}

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        build(n);
        for (int i = 0; i < n; i++) {
            int row = stones[i][0];
            int col = stones[i][1];
            if (!rowFirst.count(row)) {
                rowFirst.insert({row, i});
            }
            else {
                union_(i, rowFirst[row]);
            }
            if (!colFirst.count(col)) {
                colFirst.insert({col, i});
            }
            else {
                union_(i, colFirst[col]);
            }
        }
        return n - sets;
    }
};

int main() {
    return 0;
}