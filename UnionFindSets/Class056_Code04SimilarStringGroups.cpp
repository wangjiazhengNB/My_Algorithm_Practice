#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int father[N];
int sets;


class Solution {
public:
    int numSimilarGroups(vector<string>& s) {
        int n = s.size();
        build(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (find(i) != find(j)) {
                    int diff = 0;
                    for (int k = 0; k < s[0].size(); k++) {
                        if (s[i][k] != s[j][k]) diff++;
                        if (diff > 2) break;
                    }
                    if (diff == 0 ||diff == 2) {
                        union_(i, j);
                        sets--;
                    }
                }
            }
        }
        return sets;
    }
    void build(int n) {
        sets = 0;
        for (int i = 0; i < n; i++) {
            father[i] = i;
            sets++;
        }
    }
    int find(int x) {
        if (x != father[x]) father[x] = find(father[x]);
        return father[x];
    }
    void union_(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
        }
    }
};

int main() {
    return 0;
}