#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500005;
int arr[N];
int sort_[N];
int tree[N];

int n, m;

int lowbit(int i) {
    return i & -i;
}

void add(int i, int v) {
    while (i <= m) {
        tree[i] += v;
        i += lowbit(i);
    }
}

ll sum(int i) {
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
    //去重
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
    for (int i = n; i >= 1; i--) {
        ans += sum(arr[i] - 1);
        add(arr[i], 1);
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
}