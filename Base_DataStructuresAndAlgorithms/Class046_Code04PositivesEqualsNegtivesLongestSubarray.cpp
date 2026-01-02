#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int arr[N];
int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) arr[i] = 1;
        else if (arr[i] < 0) arr[i] = -1;
        else arr[i] = 0;
    }
    unordered_map<int, int> mp;
    mp.insert({0, -1});
    int ans = 0;
    for (int i = 0, sum = 0; i < n; i++) {
        sum += arr[i];
        if (mp.count(sum)) {
            ans = max(ans, i - mp[sum]);
        }
        else {
            mp.insert({sum, i});
        }
    }
    cout << ans;
}
