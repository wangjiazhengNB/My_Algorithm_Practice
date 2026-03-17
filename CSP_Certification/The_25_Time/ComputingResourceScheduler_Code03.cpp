#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int node_area[N];
int node_cnt[N];
unordered_set<int> node_apps[N];
unordered_set<int> area_apps[N];

int n, m, g;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> node_area[i];
    }

    cin >> g;
    while (g--) {
        int f, a, na, pa, paa, paari;
        cin >> f >> a >> na >> pa >> paa >> paari;
        vector<int> res;

        for (int task = 0; task < f; task++) {
            unordered_set<int> allowed_areas;
            if (na != 0) {
                allowed_areas.insert(na);
            }
            else {
                for (int i = 1; i <= m; i++) {
                    allowed_areas.insert(i);
                }
            }

            if (pa != 0) {
                unordered_set<int> new_allowed;
                for (int area : allowed_areas) {
                    if (area_apps[area].count(pa)) {
                        new_allowed.insert(area);
                    }
                }
                allowed_areas = new_allowed;
            }

            vector<int> candidates;
            for (int i = 1; i <= n; i++) {
                if (allowed_areas.count(node_area[i]) && 
                    (paa == 0 || !node_apps[i].count(paa))) {
                    candidates.push_back(i);
                }
            }

            if (candidates.empty() && paa != 0 && paari == 0) {
                candidates.clear();
                for (int i = 1; i < n; i++) {
                    if (allowed_areas.count(node_area[i])) {
                        candidates.push_back(i);
                    }
                }
            }

            if (candidates.empty()) {
                res.push_back(0);
                continue;
            }

            sort(candidates.begin(), candidates.end(), [&](int x, int y) {
                if (node_cnt[x] != node_cnt[y]) return node_cnt[x] < node_cnt[y];
                else return x < y;
            });

            int chosen = candidates[0];
            res.push_back(chosen);
            node_cnt[chosen]++;
            node_apps[chosen].insert(a);
            area_apps[node_area[chosen]].insert(a);
        }

        for (size_t i = 0; i < res.size(); i++) {
            if (i > 0) cout << " ";
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}