#include <bits/stdc++.h>
using namespace std;

const int N = 31;
int father[N];
int sets;


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        build(n / 2);
        for (int i = 0; i < n; i += 2) {
            union_(row[i] / 2, row[i + 1] / 2);
        }
        return n / 2 - sets;
    }
    void build(int m) {
        for (int i = 0; i < m; i++) {
            father[i] = i;
        }
        sets = m;
    }
    int find(int i) {
        if (i != father[i]) father[i] = find(father[i]);
        return father[i];
    }
    void union_(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            sets--;
        }
    }
};

int main() {
    return 0;
}