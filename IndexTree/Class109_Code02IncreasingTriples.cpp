#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 30005;
ll arr[N], sort_[N], tree1[N], tree2[N];

int n, m;

int lowbit(int i) {
    return i & -i;
}

void add(ll tree[], int i, ll c) {
    while (i <= m) {
        tree[i] += c;
        i += lowbit(i);
    }
}

ll sum(ll tree[], int i) {
    ll ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

int rank_(int v) {
    int l = 1, r = m, mid;
    int ans = 0;
    while (l <= r) {
        mid = l + r >> 1;
        if (sort_[mid] >= v) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

ll compute() {
    sort(sort_ + 1, sort_ + n + 1);
    m = 1;
    for (int i = 2; i <= n; i++) {
        if (sort_[m] != sort_[i]) {
            sort_[++m] = sort_[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = rank_(arr[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //在线查询
        ans += sum(tree2, arr[i] - 1);
        add(tree1, arr[i], 1);
        add(tree2, arr[i], sum(tree1, arr[i] - 1));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sort_[i] = arr[i];
    }
    cout << compute() << endl;
    return 0;
}

