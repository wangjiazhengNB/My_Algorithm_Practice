#include <bits/stdc++.h>
using namespace std;

const int N = 150005;

int tree[N][26];
int end_[N], pass[N], cnt;

void build() {
    cnt = 1;
}

void insert(string& word) {
    int cur = 1;
    pass[cur]++;
    for (int i = 0; i < word.size(); i++) {
        int path = word[i] - 'a';
        if (tree[cur][path] == 0) {
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
        pass[cur]++;
    }
    end_[cur]++;
}

int search(string& word) {
    int cur = 1;
    for (int i = 0; i < word.size(); i++) {
        int path = word[i] - 'a';
        if (tree[cur][path] == 0) {
            return 0;
        }
        cur = tree[cur][path];
    }
    return end_[cur];
}

int prefixSearch(string& word) {
    int cur = 1;
    for (int i = 0; i < word.size(); i++) {
        int path = word[i] - 'a';
        if (tree[cur][path] == 0) {
            return 0;
        }
        cur = tree[cur][path];
    }
    return pass[cur];
}

void erase(string& word) {
    if (search(word) > 0) {
        int cur = 1;
        pass[cur]--;
        for (int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if (--pass[tree[cur][path]] == 0) {
                tree[cur][path] = 0;
                return;
            }
            cur = tree[cur][path];
        }
        end_[cur]--;
    }
}

void clear() {
    for (int i = 1; i <= cnt; i++) {
        memset(tree[i], 0, sizeof tree[i]);
        end_[i] = 0;
        pass[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, op;
    string word;
    while (cin >> m) {
        build();
        for (int i = 1; i <= m; i++) {
            cin >> op >> word;
            if (op == 1) {
                insert(word);
            }
            else if (op == 2) {
                erase(word);
            }
            else if (op == 3) {
                cout << (search(word) > 0 ? "YES" : "NO") << '\n';
            }
            else if (op == 4) {
                cout << prefixSearch(word) << '\n';
            }
        }
        clear();
    }
    return 0;
}