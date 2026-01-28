#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int father[N];
bool secret[N];

void build(int n, int first) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
        secret[i] = false;
    }
    father[first] = 0;
    secret[0] = true;
}

int find(int x) {
    if (x != father[x]) father[x] = find(father[x]);
    return father[x];
}

void union_(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
        father[fa] = fb;
        secret[fb] |= secret[fa];
    }
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int first) {
        build(n, first);
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int m = meetings.size();
        for (int l = 0, r; l < m; ) {
            r = l;
            while (r + 1 < m && meetings[r][2] == meetings[r + 1][2]) {
                r++;
            }
            for (int i = l; i <= r; i++) {
                int a = meetings[i][0];
                int b = meetings[i][1];
                union_(a, b);
            }
            for (int i = l, a, b; i <= r; i++) {
                a = meetings[i][0];
                b = meetings[i][1];
                if (!secret[find(a)]) {
                    father[a] = a;
                }
                if (!secret[find(b)]) {
                    father[b] = b;
                }
            }
            l = r + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (secret[find(i)]) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}