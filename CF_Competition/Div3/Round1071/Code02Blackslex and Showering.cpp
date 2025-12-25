#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 200005;
ll t, n;
ll arr[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            sum += abs(arr[i] - arr[i - 1]);
        }
        ll p1 = abs(arr[0] - arr[1]);
        ll p2 = abs(arr[n - 1] - arr[n - 2]);
        ll p3 = LLONG_MIN;
        for (int i = 1; i < n - 1; i++) {
            p3 = max(p3, abs(arr[i - 1] - arr[i]) + abs(arr[i] - arr[i + 1]) - abs(arr[i - 1] - arr[i + 1]));
        }
        ll p = max(p1, max(p2, p3));
        sum -= p;
        cout << sum << endl;
    }
    return 0;
}