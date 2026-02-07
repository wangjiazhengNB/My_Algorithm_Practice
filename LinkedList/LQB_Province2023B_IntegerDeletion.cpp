#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int w[N], l[N], r[N];
bool exist[N];
int n, k;

struct Node {#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

long long w[N];
int l[N], r[N];
bool exist[N];
int n, k;

struct Node {
    long long a;
    int idx;
    bool operator>(const Node& C) const {
        if (a != C.a) return a > C.a;
        return idx > C.idx;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    priority_queue<Node, vector<Node>, greater<Node>> heap;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        l[i] = i - 1;
        r[i] = i + 1;
        exist[i] = true;
        heap.push({w[i], i});
    }
    l[1] = 0;
    r[n] = 0;

    while (k--) {
        Node cur = heap.top();
        heap.pop();
        long long a = cur.a;
        int idx = cur.idx;

        if (!exist[idx] || w[idx] != a) {
            k++;
            continue;
        }

        exist[idx] = false;
        int left = l[idx], right = r[idx];

        if (left) {
            w[left] += a;
            heap.push({w[left], left});
            r[left] = right;
        }

        if (right) {
            w[right] += a;
            heap.push({w[right], right});
            l[right] = left;
        }
    }

    vector<long long> ans;
    int p = 1;
    while (p) {
        if (exist[p]) ans.push_back(w[p]);
        p = r[p];
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
    int a, idx;
    bool operator>(const Node& C) const {
        if (a != C.a) return a > C.a;
        return idx > C.idx;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    priority_queue<Node, vector<Node>, greater<Node>> heap;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        l[i] = i - 1;
        r[i] = i + 1;
        exist[i] = true;
        heap.push({w[i], i});
    }
    l[1] = 0;
    r[n] = 0;

    while (k--) {
        Node cur = heap.top();
        heap.pop();
        int a = cur.a;
        int idx = cur.idx;

        if (!exist[idx] || w[idx] != a) {
            k++;
            continue;
        }

        exist[idx] = false;
        int left = l[idx], right = r[idx];

        if (left) {
            w[left] += a;
            heap.push({w[left], left});
            r[left] = right;
        }

        if (right) {
            w[right] += a;
            heap.push({w[right], right});
            l[right] = left;
        }
    }

    vector<int> ans;
    int p = 1;
    while (p) {
        if (exist[p]) ans.push_back(w[p]);
        p = r[p];
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}