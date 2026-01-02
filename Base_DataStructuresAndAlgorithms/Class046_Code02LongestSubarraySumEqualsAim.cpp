#include <bits/stdc++.h>
using namespace std;


const int N = 100005;
int arr[N];
int n, aim;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> aim;
    unordered_map<int, int> mp;
    mp.insert({0, -1});
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0, sum = 0; i < n; i++) {
        sum += arr[i];
        if (mp.count(sum - aim)) {
            ans = max(ans, i - mp[sum - aim]);
        }
        if (!mp.count(sum)) {
            mp.insert({sum, i});
        }
    }
    cout << ans;
    return 0;
}
