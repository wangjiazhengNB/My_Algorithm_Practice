#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> hashMap;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s = "";
        for (int j = 1; j <= 8; j++) {
            string str;
            cin >> str;
            s += str;
        }
        hashMap[s]++;
        cout << hashMap[s] << '\n';
    }
    return 0;
}