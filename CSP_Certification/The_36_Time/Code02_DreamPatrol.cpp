#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;
long long a[N];
long long b[N];
long long S[N];
long long left_max[N];
long long right_max[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    long long sum_a = 0;
    long long sum_b = 0;
    for (int i = 0; i <= n; i++) {
        sum_a += a[i];
        if (i >= 1) sum_b += b[i];
        S[i] = sum_a - sum_b;
    }

    left_max[1] = S[0];
    for (int i = 2; i <= n; i++) {
        left_max[i] = max(left_max[i-1], S[i-1]);
    }

    right_max[n] = S[n];
    for (int i = n-1; i >= 1; i--) {
        right_max[i] = max(right_max[i+1], S[i]);
    }

    vector<long long> ans;
    for (int i = 1; i <= n; i++) {
        long long res = max(left_max[i], right_max[i] + b[i]);
        ans.push_back(res);
    }

    for (auto v : ans) {
        cout << v << " ";
    }
    return 0;
}