#include <bits/stdc++.h>
using namespace std;


#define ll long long
const int N = 200005;
int t, n;
ll arr[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 1; i < n; i++) {
            sum += abs(arr[i] - arr[i - 1]);
        }
        ll t1 = abs(arr[0] - arr[1]);
        ll t2 = abs(arr[n - 1] - arr[n - 2]);
        ll t3 = LLONG_MIN;
        for (int i = 1; i < n - 1; i++) {
            t3 = max(t3, abs(arr[i - 1] - arr[i]) + abs(arr[i] - arr[i + 1]) - abs(arr[i - 1] - arr[i + 1]));
        }
        ll t = max(t1, max(t2, t3));
        ll ans = sum - t;
        cout << ans << endl;
    }
    return 0;
}