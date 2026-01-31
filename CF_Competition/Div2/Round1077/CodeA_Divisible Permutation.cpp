#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> p;
        unordered_set<int> used;
        p.push_back(1), p.push_back(n);
        used.insert(1), used.insert(n);
        for (int i = n - 2; i >= 1; i--) {
            int prev = p.back();
            int candidate1 = prev - i;
            if (candidate1 >= 1 && candidate1 <= n && used.find(candidate1) == used.end()) {
                p.push_back(candidate1);
                used.insert(candidate1);
            }
            else {
                int candidate2 = prev + i;
                p.push_back(candidate2);
                used.insert(candidate2);
            }    
        }
        reverse(p.begin(), p.end());
        for (int num : p) {
            cout << num << " ";
        }
        cout << '\n';
    }
    return 0;
}

// O(n)