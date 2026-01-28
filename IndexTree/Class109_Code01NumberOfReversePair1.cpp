#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500005;

int arr[N];
int help[N];

int n;

ll merge_(int l, int m, int r);

ll f(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = l + r >> 1;
    return f(l, m) + f(m + 1, r) + merge_(l, m, r);
}

ll merge_(int l, int m, int r) {
    ll ans = 0;
    for (int i = m, j = r; i >= l; i--) {
        while (j >= m + 1 && arr[i] <= arr[j]) {
            j--;
        }
        ans += j - m;
    }
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = (arr[a] <= arr[b]) ? arr[a++] : arr[b++];
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return ans;
}

ll compute() {
    return f(1, n);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << compute() << endl;
    return 0;
}