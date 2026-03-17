#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

const int MAX_DAY = 100005;
unordered_map<int, map<int, int>> g;
vector<tuple<int, int, int>> events[MAX_DAY];

//40 ~ 60 分

int islet, pair_cnt;
int n, m;

int get_main(int x) {
    int max_friend = 0, max_score = 0;
    for (auto [friend_id, score] : g[x]) {
        if (score > max_score) {
            max_score = score;
            max_friend = friend_id;
        }
    }
    return max_friend;
} 

void update(int u, int v, int add) {
    g[u][v] += add;
    g[v][u] += add;
    if (g[u][v] <= 0) {
        g[u].erase(v);
        g[v].erase(u);
    }

    islet = 0;
    pair_cnt = 0;
    for (int i = 1; i <= n; i++) {
        int my_main = get_main(i);
        if (my_main == 0) {
            islet++;
        }
        if (my_main > i && get_main(my_main) == i) {
            pair_cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    islet = n;
    for (int day = 1; day <= m; day++) {
        for (auto [u, v, val] : events[day]) {
            update(u, v, val);
        }

        int k;
        cin >> k;
        while (k--) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            update(u, v, x);
            if (day + y <= m + 1) {
                events[day + y].emplace_back(u, v, -x);
            }
        }

        int l;
        cin >> l;
        while (l--) {
            int u;
            cin >> u;
            cout << get_main(u) << '\n';
        }

        int p, q;
        cin >> p >> q;
        if (p == 1) cout << islet << '\n';
        if (q == 1) cout << pair_cnt << '\n';
    }
    return 0;
}