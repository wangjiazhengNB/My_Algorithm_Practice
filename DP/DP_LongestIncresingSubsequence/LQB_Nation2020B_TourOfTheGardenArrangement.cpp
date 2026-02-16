#include <bits/stdc++.h>
using namespace std;

int bs(vector<string>& ends, int len, string& target) {
    int l = 0, r = len - 1, m;
    int ans = -1;
    while (l <= r) {
        m = l + r >> 1;
        if (ends[m] >= target) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
}

string LIS(vector<string>& names) {
    int n = names.size();
    if (n == 0) return "";
    vector<string> ends(n), dp(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        string cur_name = names[i];
        int find = bs(ends, len, cur_name);
        if (find == -1) {
            ends[len] = cur_name;
            dp[len] = (len == 0) ? cur_name : dp[len - 1] + cur_name;
            len++;
        }
        else {
            ends[find] = cur_name;
            dp[find] = (find == 0) ? cur_name : dp[find - 1] + cur_name;
        }
    }
    return dp[len - 1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector<string> names;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            names.push_back(string(1, s[i]));
        }
        else {
            if (!names.empty()) {
                names.back() += s[i];
            }
        }
    }
    string ans = LIS(names);
    cout << ans << '\n';
    return 0;
}