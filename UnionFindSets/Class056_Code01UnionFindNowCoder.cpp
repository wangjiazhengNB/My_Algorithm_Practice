#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int father[N];
int size_[N];
int stack_[N];
int n, m;

void build() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        size_[i] = 1;
    }
}

int find(int i) {
    int cnt = 0;
    while (i != father[i]) {
        stack_[cnt++] = i;
        i = father[i]; 
    }
    while (cnt > 0) {
        father[stack_[--cnt]] = i; 
    }
    return i;
}

void union_(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    if (size_[fx] >= size_[fy]) {
        size_[fx] += size_[fy];
        father[fy] = fx;
    } 
    else {
        size_[fy] += size_[fx];
        father[fx] = fy;
    }
}

bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    build();
    for (int i = 0, op, x, y; i < m; i++) {
        cin >> op >> x >> y;
        if (op == 1) {
            if (isSameSet(x, y)) {
                cout << "Yes" << "\n";
            }
            else {
                cout << "No" << "\n";
            }
        }
        else {
            union_(x, y);
        }
    }
}
